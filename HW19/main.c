#include <unistd.h>
#include <ncurses/ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>

#define MIN_Y 2
#define PLAYERS 2
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10, SEED_NUMBER=10};

struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;
//struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};
struct control_buttons pleer1_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};
struct control_buttons pleer2_controls = {'s', 'w', 'a', 'd'};

typedef struct tail_t
{
    int x;
    int y;
} tail_t;

typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    tail_t *tail;
    struct control_buttons controls;
} snake_t;

void initTail(tail_t t[], size_t size)
{
    tail_t init_t = {0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}

void initHead(snake_t *head, int x, int y)
{
    head->x = x; 
    head->y = y;
    head->direction = DOWN;
}

void initSnake(snake_t *head[], size_t size, int x, int y, int i)
{
    head[i] = (snake_t*) malloc(sizeof(snake_t));
    tail_t *tail = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->tail = tail;
    head[i]->tsize = size; // Храним реальное количество элементов хвоста
    //head[i]->controls = default_controls;
}

void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}

void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x);
    
    // Стираем старую еду перед генерацией новой
    if (fp->enable) {
        mvprintw(fp->y, fp->x, " ");
    }
    
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 2; // Оставляем верхнюю строчку под инфо
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    
    mvprintw(fp->y, fp->x, "%c", fp->point);
}

void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
    {
        if(f[i].put_time)
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS)
            {
                putFoodSeed(&f[i]);
            } 
        }
    }
}


void go(snake_t *head)
{
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x);
    
    switch(head->direction)
    {
        case LEFT:
            if(head->x <= 0) head->x = max_x - 1;
            else head->x--;
            break;
        case RIGHT:
            if(head->x >= max_x - 1) head->x = 0;
            else head->x++;
            break;
        case UP:
            if(head->y <= MIN_Y) head->y = max_y - 1;
            else head->y--;
            break;
        case DOWN:
            if(head->y >= max_y - 1) head->y = MIN_Y;
            else head->y++;
            break;
    }
}

void update(struct snake_t *head)
{
    char prev_ch = '*';
    char head_ch = '@';
    
    // Стираем самый последний элемент хвоста
    if (head->tail[head->tsize-1].x != 0 || head->tail[head->tsize-1].y != 0) {
        mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    }
    
    // Сдвигаем координаты хвоста в массиве
    for(size_t i = head->tsize-1; i > 0; i--)
    {
        head->tail[i] = head->tail[i-1];
    }
    
    // Бывшая позиция головы становится началом хвоста
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
    
    // Отрисовываем первый элемент хвоста на старом месте головы
    mvprintw(head->tail[0].y, head->tail[0].x, "%c", prev_ch);
    
    // Двигаем голову на новые координаты
    go(head);
    
    // Рисуем голову на новом месте
    mvprintw(head->y, head->x, "%c", head_ch);
}

void changeDirection(snake_t *snake, const int32_t key)
{
    if(key == snake->controls.down)// || key=='S' || key=='s')
        snake->direction = DOWN;
    else if(key == snake->controls.up)// || key=='W' || key=='w')
        snake->direction = UP;
    else if(key == snake->controls.right)// || key=='D' || key=='d')
        snake->direction = RIGHT;
    else if(key == snake->controls.left)// || key=='A' || key=='a')
        snake->direction = LEFT;
}

int checkCollision(snake_t *head)
{
    // Проверяем столкновение только с активными частями хвоста
    for (size_t i=0; i < head->tsize; i++) {
        if (head->tail[i].x == head->x && head->tail[i].y == head->y)
            return 1;
    }
    return 0;
}

int checkDirection(snake_t *snake, int32_t key)
{
    if(snake->direction==LEFT && (key==KEY_RIGHT || key=='D' || key=='d'))
        return 0;
    else if(snake->direction==RIGHT && (key==KEY_LEFT || key=='A' || key=='a'))
        return 0;
    else if(snake->direction==UP && (key==KEY_DOWN || key=='S' || key=='s'))
        return 0;
    else if(snake->direction==DOWN && (key==KEY_UP || key=='W' || key=='w'))
        return 0;
    else
        return 1;
}

_Bool haveEat(snake_t *head, struct food f[], int size)
{
    for(size_t i=0; i<size; i++)
    {
        if( f[i].enable!=0 && head->x==f[i].x && head->y==f[i].y)
        {
            f[i].enable = 0;
            return 1;
        }
    }
    return 0;
}

void addTail(snake_t *head)
{
    if(head->tsize < MAX_TAIL_SIZE)
    {
        head->tsize++;
    }
}

void repairSeed(struct food f[], size_t nfood, struct snake_t *head)
{
    _Bool has_collision;

    do {
        has_collision = 0;

        for (size_t i = 0; i < nfood; i++) {
            // Проверяем только активные зерна
            if (!f[i].enable) {
                continue;
            }

            //Проверка на совпадение с хвостом змейки
            for (size_t k = 0; k < head->tsize; k++) {
                // Исключаем пустые элементы хвоста (если они инициализированы нулями)
                if (head->tail[k].x == 0 && head->tail[k].y == 0) {
                    continue;
                }
                
                if (f[i].x == head->tail[k].x && f[i].y == head->tail[k].y) {
                    putFoodSeed(&f[i]);
                    has_collision = 1;
                    break;
                }
            }
            if (has_collision) break;

            // Проверка на совпадение с другими зернами
            for (size_t j = 0; j < nfood; j++) {
                if (i != j && f[j].enable && f[i].x == f[j].x && f[i].y == f[j].y) {
                    putFoodSeed(&f[i]);
                    has_collision = 1;
                    break;
                }
            }
            if (has_collision) break;
        }
    } while (has_collision); // Цикл продолжается, пока есть хоть одно пересечение
}


//========================================
int main(void)
{
    srand(time(NULL)); // Инициализация генератора случайных чисел
    
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    
    //snake_t *snake = (snake_t*) malloc(sizeof(snake_t));
    snake_t *snakes[PLAYERS];
    for (int i=0; i<PLAYERS; i++)
        initSnake(snakes, START_TAIL_SIZE, 10+i*10, 10+i*10, i);
    snakes[0]->controls = pleer1_controls;
    snakes[1]->controls = pleer2_controls;
    
    mvprintw(0, 0, "Use arrows for control. Press 'F10' for EXIT");
    refresh();
    
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);

    int key_pressed=0;
    timeout(100);
    
    int game_over=0;
    while( key_pressed != STOP_GAME)
    {
        key_pressed = getch();

        for(int i=0; i<PLAYERS; i++)
        {
            
            if(checkDirection(snakes[i], key_pressed))
            changeDirection(snakes[i], key_pressed);

            attron(COLOR_PAIR(i+1));
            update(snakes[i]);
            attroff(COLOR_PAIR(i+1));

            refreshFood(food, SEED_NUMBER);
            repairSeed(food, SEED_NUMBER, snakes[i]);
            if(haveEat(snakes[i], food, MAX_FOOD_SIZE))
            {
                attron(COLOR_PAIR(i+1));
                addTail(snakes[i]);
                attroff(COLOR_PAIR(i+1));
            }
            if (checkCollision(snakes[i]))
            {
                timeout(-1); 
                int max_x = 0, max_y = 0;
                getmaxyx(stdscr, max_y, max_x);
                mvprintw(max_y / 2, (max_x / 2) - 12, "GAME OVER! Press any key");
                refresh();
                getch();
                game_over = 1;
                break;
            }
            
        }
        if(game_over)
            break;
        refresh();
    }

    for(int i=0; i<PLAYERS; i++)
    {
        free(snakes[i]->tail);
        free(snakes[i]);
    }
    endwin();

    return 0;
}
