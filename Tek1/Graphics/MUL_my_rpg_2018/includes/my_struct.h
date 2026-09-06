/*
** EPITECH PROJECT, 2019
** my_struct.h
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

typedef struct variable_s
{
    bool pause;
    int quit_beach;
    int quit_donjon;
    int level;
    int fullscreen;
    int chara;
    int potion;
    int score_of_file;
    int time_of_file;
    int kill_of_file;
    int score;
    int time;
    int kill;
    int slot_skill_one;
    int slot_skill_two;
    int slot_skill_three;
    int slot_skill_four;
    unsigned short move;
    bool disp_dial;
    bool disp_music;
    bool disp_inventory;
    int player_hp;
    int player_mana;
    int go_to_end;
    int player_speed;
    int player_xp;
    unsigned int spell_range;
    int spell_speed;
    int spell_dmg;
    float enemy_eye_speed;
    int enemy_eye_agro_range;
    int enemy_eye_dmg;
    int enemy_eye_earn;
    float enemy_spider_speed;
    int enemy_spider_range;
    int enemy_spider_dmg;
    int enemy_spider_earn;
    float enemy_evil_tick_speed;
    int enemy_evil_tick_range;
    int enemy_evil_tick_dmg;
    int enemy_evil_tick_earn;
} variable_t;

typedef struct map_s
{
    char **beach;
} map_t;

typedef struct player_s
{
    int attack;
    int rect_x;
    int rect_y;
    int status;
    int hp;
    int mana;
    int gold;
    int xp;
    int regen_hp;
    int regen_mana;
    int speed_move;
    int speed_attack;
    int armor;
    int attack_basic;
    int attack_spell;
    int animation;
    sfIntRect **rect;
    sfClock *clock;
    sfClock *clock_time_score;
    sfClock *clock_regen;
    sfTime time;
} player_t;

typedef struct vector_s
{
    sfVector2f mouse;
    sfVector2i twoi;
} vector_t;

typedef struct enemy_eye_s
{
    sfVector2f pos;
    sfClock *anim;
    sfClock *attack;
    sfIntRect rect;
    short health;
    struct enemy_eye_s *next;
} enemy_eye_t;

typedef struct enemy_evil_tick_s
{
    sfVector2f pos;
    sfClock *anim;
    sfClock *attack;
    sfIntRect rect;
    short health;
    struct enemy_evil_tick_s *next;
} enemy_evil_tick_t;

typedef struct enemy_spider_s
{
    sfVector2f pos;
    sfClock *anim;
    sfClock *attack;
    sfIntRect rect;
    short health;
    struct enemy_spider_s *next;
} enemy_spider_t;

typedef struct enemy_eye_bomb_s
{
    sfVector2f pos;
    sfClock *anim;
    sfIntRect rect;
    struct enemy_eye_bomb_s *next;
} enemy_eye_bomb_t;

typedef struct boss_s
{
    unsigned short attack_status;
    sfIntRect rect;
    sfClock *anim;
    sfClock *attack;
    short health;
    sfText *attempt_attack;
    sfRectangleShape *health_display;
} boss_t;

typedef struct particle_spell_s
{
    sfVector2f pos;
    unsigned short fade;
    struct particle_spell_s *next;
} particle_spell_t;

typedef struct projectile_spell_s
{
    sfVector2f pos;
    sfVector2f speed;
    sfClock *clock_move;
    sfClock *clock_particle;
    unsigned int number_move;
    struct projectile_spell_s *next;
} projectile_spell_t;

typedef struct particle_boss_s
{
    sfVector2f pos;
    unsigned short fade;
    struct particle_boss_s *next;
} particle_boss_t;

typedef struct projectile_boss_s
{
    sfVector2f pos;
    sfVector2f speed;
    sfClock *clock_move;
    sfClock *clock_particle;
    unsigned int number_move;
    struct projectile_boss_s *next;
} projectile_boss_t;

typedef struct item_s
{
    unsigned short f;
    sfClock *clock;
    sfVector2f posi;
    sfIntRect rect;
    struct item_s *next;
} item_t;

typedef struct particle_s
{
    sfRectangleShape *rectangle;
    sfRectangleShape *spell;
    sfRectangleShape *boss;
} particle_t;

typedef struct rain_particle_s
{
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f speed;
    int limit;
    int animation;
    unsigned int clock;
    struct rain_particle_s *next;
} rain_particle_t;

typedef struct skill_s
{
    sfIntRect rect;
    int number;
    int choose;
    char *text;
    struct skill_s *next;
} skill_t;

typedef struct menu_particle_s
{
    sfVector2f speed;
    sfVector2f pos;
    sfVector2f size;
    struct menu_particle_s *next;
} menu_particle_t;

typedef struct intro_s
{
    unsigned char fade;
    unsigned char alpha;
    sfRectangleShape *rectangle;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *anim;
} intro_t;

typedef struct sprite_s
{
    sfSprite *cursor;
    sfSprite *player;
    sfSprite *pnj_beach;
    sfSprite *menu;
    sfSprite *play1_menu;
    sfSprite *play2_menu;
    sfSprite *set1_menu;
    sfSprite *set2_menu;
    sfSprite *htp1_menu;
    sfSprite *htp2_menu;
    sfSprite *exit1_menu;
    sfSprite *exit2_menu;
    sfSprite *high_score1_menu;
    sfSprite *high_score2_menu;
    sfSprite *beach_intro;
    sfSprite *beach_intro2;
    sfSprite *hud_menu;
    sfSprite *hud_set;
    sfSprite *logo;
    sfSprite *size_1920_1;
    sfSprite *size_1664_1;
    sfSprite *size_1280_1;
    sfSprite *size_1920_2;
    sfSprite *size_1664_2;
    sfSprite *size_1280_2;
    sfSprite *key_bindings_1;
    sfSprite *key_bindings_2;
    sfSprite *fullscreen;
    sfSprite *vsync;
    sfSprite *chara_menu_hud;
    sfSprite *chara_menu1;
    sfSprite *chara_menu2;
    sfSprite *chara_menu3;
    sfSprite *chara_menu4;
    sfSprite *chara_menu5;
    sfSprite *rain;
    sfSprite *pause_menu;
    sfSprite *donjon;
    sfSprite *donjon_shader;
    sfSprite *donjon_torch;
    sfSprite *donjon_wall;
    sfSprite *dialog;
    sfSprite *eye;
    sfSprite *inventory;
    sfSprite *hud;
    sfSprite *back_pause;
    sfSprite *resume_1;
    sfSprite *resume_2;
    sfSprite *btm_1;
    sfSprite *btm_2;
    sfSprite *quit_1;
    sfSprite *quit_2;
    sfSprite *item;
    sfSprite *eye_bomb;
    sfSprite *spider;
    sfSprite *evil_tick;
    sfSprite *back_htp;
    sfSprite *back_hs;
    sfSprite *skill;
    sfSprite *music_but;
    sfSprite *boss;
} sprite_t;

typedef struct texture_s
{
    sfTexture *cursor;
    sfTexture *player;
    sfTexture *pnj_beach;
    sfTexture *menu;
    sfTexture *play1_menu;
    sfTexture *play2_menu;
    sfTexture *set1_menu;
    sfTexture *set2_menu;
    sfTexture *htp1_menu;
    sfTexture *htp2_menu;
    sfTexture *exit1_menu;
    sfTexture *exit2_menu;
    sfTexture *high_score1_menu;
    sfTexture *high_score2_menu;
    sfTexture *beach_intro;
    sfTexture *beach_intro2;
    sfTexture *hud_menu;
    sfTexture *hud_set;
    sfTexture *logo;
    sfTexture *size_1920_1;
    sfTexture *size_1664_1;
    sfTexture *size_1280_1;
    sfTexture *size_1920_2;
    sfTexture *size_1664_2;
    sfTexture *size_1280_2;
    sfTexture *key_bindings_1;
    sfTexture *key_bindings_2;
    sfTexture *fullscreen;
    sfTexture *vsync;
    sfTexture *chara_menu_hud;
    sfTexture *chara_menu1;
    sfTexture *chara_menu2;
    sfTexture *chara_menu3;
    sfTexture *chara_menu4;
    sfTexture *chara_menu5;
    sfTexture *rain;
    sfTexture *pause_menu;
    sfTexture *donjon;
    sfTexture *donjon_shader;
    sfTexture *donjon_torch;
    sfTexture *donjon_wall;
    sfTexture *dialog;
    sfTexture *eye;
    sfTexture *inventory;
    sfTexture *hud;
    sfTexture *back_pause;
    sfTexture *resume_1;
    sfTexture *resume_2;
    sfTexture *btm_1;
    sfTexture *btm_2;
    sfTexture *quit_1;
    sfTexture *quit_2;
    sfTexture *item;
    sfImage *donjon_hitbox;
    sfTexture *eye_bomb;
    sfTexture *spider;
    sfTexture *evil_tick;
    sfTexture *back_htp;
    sfTexture *back_hs;
    sfTexture *skill;
    sfTexture *music_but;
    sfTexture *boss;
} texture_t;

typedef struct rect_s
{
    sfIntRect full_but;
    sfIntRect music_but;
    sfIntRect knight_a;
    sfIntRect priest_a;
    sfIntRect sorcerer_a;
    sfIntRect thief_a;
    sfIntRect wizard_a;
    sfIntRect player;
    sfIntRect pnj_beach;
    sfIntRect donjon_torch;
} rect_t;

typedef struct text_s
{
    sfText *kgnight_menu;
    sfText *priest_menu;
    sfText *sorcerer_menu;
    sfText *thief_menu;
    sfText *wizard_menu;
    sfText *vsync;
    sfText *fullscreen;
    sfText *text_highscore;
    sfFont *font_highscore;
    sfFont *game_police;
    sfText *launch_dial;
    sfText *dialog;
    sfText *pnj_answ;
    sfText *player_answ;
    sfText *pnj_name;
    sfText *player_name;
    sfText *player_hp;
    sfText *player_hp_max;
    sfText *player_regen_hp;
    sfText *player_gold;
    sfText *player_mana;
    sfText *player_mana_max;
    sfText *player_armor;
    sfText *player_regen_mana;
    sfText *player_basic_attack;
    sfText *player_spell_attack;
    sfText *player_attack_speed;
    sfText *player_move_speed;
    sfText *press_space;
    sfText *text_htp;
    sfText *hs;
    sfText *hs_score;
    sfText *hs_time;
    sfText *hs_kill;
    sfText *music;
} text_t;

typedef struct music_s
{
    sfMusic *menu;
    sfMusic *rain;
    sfMusic *dungeon_theme;
    sfMusic *boss_theme;
    sfSoundBuffer *sand1_buffer;
    sfSoundBuffer *sand2_buffer;
    sfSoundBuffer *sand3_buffer;
    sfSound *sand1;
    sfSound *sand2;
    sfSound *sand3;
    sfSoundBuffer *spell_buffer;
    sfSound *spell;
    sfSoundBuffer *flesh_slice_buffer;
    sfSound *flesh_slice;
    sfSoundBuffer *sword_slash_buffer;
    sfSound *sword_slash;
} music_t;

typedef struct clocker_s
{
    sfClock *particle;
    sfClock *anim;
    sfClock *regeneration;
    sfClock *donjon_torch;
    sfClock *spell_particle;
    sfClock *boss_particle;
    sfClock *trap;
    sfClock *end_game;
    sfClock *enemy_manage;
    sfClock *footsteps_sound;
    sfClock *spell_sound;
    sfClock *player_move;
    sfClock *flesh_sound;
} clocker_t;

typedef struct my_time_s
{
    sfTime useless;
} my_timer_t;

typedef struct view_s
{
    sfView *view;
    sfVector2f offset;
} view_t;

typedef struct window_s
{
    float ratio;
    sfRenderWindow *dow;
    sfEvent event;
} window_t;

typedef struct button_s
{
    bool escape;
    bool click;
    bool vsync;
    bool fullscreen;
    bool space;
    bool rightclick;
    bool inventory;
    bool click_music;
} button_t;

typedef struct rectangle_s
{
    sfRectangleShape *knight_menu;
    sfRectangleShape *priest_menu;
    sfRectangleShape *sorcerer_menu;
    sfRectangleShape *thief_menu;
    sfRectangleShape *wizard_menu;
}rectangle_t;

typedef struct game_s
{
    variable_t var;
    view_t view;
    window_t win;
    text_t text;
    vector_t vector;
    rect_t rect;
    rectangle_t rectangle;
    button_t press;
    my_timer_t time;
    map_t map;
    player_t player;
    intro_t *intro;
    sprite_t *sprite;
    texture_t *texture;
    clocker_t *clock;
    music_t *music;
    particle_t *particle;
    struct skill_s *skill;
    struct item_s *item;
    struct rain_particle_s *rain_particle;
    struct menu_particle_s *menu_particle;
    struct projectile_spell_s *projectile_spell;
    struct particle_spell_s *particle_spell;
    struct projectile_boss_s *projectile_boss;
    struct particle_boss_s *particle_boss;
    struct enemy_eye_s *enemy_eye;
    struct enemy_eye_bomb_s *enemy_eye_bomb;
    struct enemy_spider_s *enemy_spider;
    struct enemy_evil_tick_s *enemy_evil_tick;
    struct boss_s boss;
} game_t;

#endif
