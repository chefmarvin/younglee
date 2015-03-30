#ifndef YOUNGLEE_H
#define YOUNGLEE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>

#define ON    1
#define OFF   0
#define TRUE  1
#define FALSE 0
#define JCHARS 210

int BASIC          = OFF;
int EDUCATION      = OFF;
int WORKEXPERIENCE = OFF;
int PROJECTS       = OFF;
int SKILLS         = OFF;
int MAIL           = OFF;
int HOMEPAGE       = OFF;
int LINKS          = OFF;
wchar_t jchars[210] = { 'ぁ', 'あ', 'ぃ', 'い', 'ぅ', 'う', 'ぇ', 'え', 'ぉ', 'お', 'か', 'が', 'き', 'ぎ', 'く',
                        'ぐ', 'け', 'げ', 'こ', 'ご', 'さ', 'ざ', 'し', 'じ', 'す', 'ず', 'せ', 'ぜ', 'そ', 'ぞ', 'た',
                        'だ', 'ち', 'ぢ', 'っ', 'つ', 'づ', 'て', 'で', 'と', 'ど', 'な', 'に', 'ぬ', 'ね', 'の', 'は',
                        'ば', 'ぱ', 'ひ', 'び', 'ぴ', 'ふ', 'ぶ', 'ぷ', 'へ', 'べ', 'ぺ', 'ほ', 'ぼ', 'ぽ', 'ま', 'み',
                        'む', 'め', 'も', 'ゃ', 'や', 'ゅ', 'ゆ', 'ょ', 'よ', 'ら', 'り', 'る', 'れ', 'ろ', 'ゎ', 'わ',
                        'ゐ', 'ゑ', 'を', 'ん', 'ゔ', 'ゕ', 'ゖ', '゙', '゚', '゛', '゜', 'ゝ', 'ゞ', 'ゟ',
                        '゠', 'ァ', 'ア', 'ィ', 'イ', 'ゥ', 'ウ', 'ェ', 'エ', 'ォ', 'オ', 'カ', 'ガ', 'キ', 'ギ', 'ク',
                        'グ', 'ケ', 'ゲ', 'コ', 'ゴ', 'サ', 'ザ', 'シ', 'ジ', 'ス', 'ズ', 'セ', 'ゼ', 'ソ', 'ゾ', 'タ',
                        'ダ', 'チ', 'ヂ', 'ッ', 'ツ', 'ヅ', 'テ', 'デ', 'ト', 'ド', 'ナ', 'ニ', 'ヌ', 'ネ', 'ノ', 'ハ',
                        'バ', 'パ', 'ヒ', 'ビ', 'ピ', 'フ', 'ブ', 'プ', 'ヘ', 'ベ', 'ペ', 'ホ', 'ボ', 'ポ', 'マ', 'ミ',
                        'ム', 'メ', 'モ', 'ャ', 'ヤ', 'ュ', 'ユ', 'ョ', 'ヨ', 'ラ', 'リ', 'ル', 'レ', 'ロ', 'ヮ', 'ワ',
                        'ヰ', 'ヱ', 'ヲ', 'ン', 'ヴ', 'ヵ', 'ヶ', 'ヷ', 'ヸ', 'ヹ', 'ヺ', 'ー', 'ヽ', 'ヾ', 'ヿ',
                        'ㇰ', 'ㇱ', 'ㇲ', 'ㇳ', 'ㇴ', 'ㇵ', 'ㇶ', 'ㇷ', 'ㇸ', 'ㇹ', 'ㇺ', 'ㇻ', 'ㇼ', 'ㇽ', 'ㇾ', 'ㇿ' };    /* TODO: with unicode support */

int getOption(char *opt);
int basicInfo(void);
int showDetails(void);

int
basic(void)
{
    printf("Basic: \n\t");

    return TRUE;
}

int
education()
{
    printf("Education: \n\t");

    return TRUE;
}

int
getOption(char *opt)
{
    extern int BASIC, WEBSTACK;

    while ('\0' != *opt)
    {
        switch (*opt++)
        {
            case 'b': BASIC          = ON; break; 
            case 'e': EDUCATION      = ON; break;
            case 'w': WORKEXPERIENCE = ON; break;
            case 'p': PROJECTS       = ON; break;
            case 's': SKILLS         = ON; break;
            case 'm': MAIL           = ON; break;
            case 'h': HOMEPAGE       = ON; break;
            case 'l': LINKS          = ON; break;
            default: break;
        }
    }
}

#endif /* YOUNGLEE_H */
