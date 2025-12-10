#define _CRT_SECURE_NO_WARNINGS
#include "video.h"

// µ¥ÀÌÅÍÀÇ ¹«°á¼ºÀÌ¶õ? 
// 1. µ¥ÀÌÅÍÀÇ Á¤È®¼º, ¿ÏÀü¼º, ÀÏ°ü¼º ¹× À¯È¿¼ºÀÌ À¯ÁöµÇ´Â Æ¯¼ºÀ» ¸»ÇÑ´Ù.
// 2. µ¥ÀÌÅÍ°¡ ½ÇÁ¦ Çö½ÇÀ» Á¤È®ÇÏ°Ô ¹İ¿µÇÑ´Ù´Â °ÍÀ» ÀÇ¹ÌÇÑ´Ù.
// 3. ¿À·ù³ª ¹«ÇÑÇÑ °ªÀÌ ¾øÀ¸¸ç, µ¥ÀÌÅÍ°¡ °³¹ßÀÚÀÇ »ı°¢´ë·Î À¯ÁöµÇ¾î¾ß ÇÑ´Ù.
// µ¥ÀÌÅÍÀÇ Á¤ÇÕ¼ºÀÌ¶õ?
// µ¥ÀÌÅÍ°¡ ÀÏ°ü¼º ÀÖ°Ô À¯ÁöµÇ´Â °ÍÀ» ÀÇ¹ÌÇÑ´Ù.
// µ¥ÀÌÅÍ°£ ¸ğ¼øÀÌ³ª, Áßº¹ÀÌ ¾ø¾î¾ß ÇÏ°í, µ¥ÀÌÅÍÀÇ ³í¸®Àû ±¸Á¶°¡ ÀÏ°üµÇ¾î¾ß ÇÑ´Ù.4
// °øÅëÁ¡Àº ¹«¾ùÀÎ°¡?
// ¹«°á¼ºÀº Á¤È®¼º, ¿ÏÀü¼º, ÀÏ°ü¼º, À¯È¿¼ºÀÌ ¸ğµÎ À¯ÁöµÇ¾î µ¥ÀÌÅÍ°¡ ¿Ã¹Ù¸£°Ô À¯ÁöµÈ »óÅÂÀÌ´Ù.
// Á¤ÇÕ¼ºÀº ¿©·¯ µ¥ÀÌÅÍ°£ ÀÏ°ü¼ºÀÌ À¯ÁöµÈ »óÅÂÀÌ´Ù.
// µ¥ÀÌÅÍÀÇ ÀÏ°ü¼ºÀÌ¶õ?
// µ¥ÀÌÅÍº£ÀÌ½ºÀÇ ¸ğµç ³»¿ëÀÌ ¸ğ¼øµÇÁö ¾Ê´Â °ÍÀ» ÀÇ¹ÌÇÑ´Ù.

// °Ë»öÇÔ¼ö¿¡¼­ µ¥ÀÌÅÍÀÇ ÀÏ°ü¼ºÀ» ÁöÅ°±â À§ÇØ¼­ ÁøÇàÇÑ°Í
// ¿ì¼± °ü¸®ÀÚ ¸ğµå°¡ ½ÇÇàµÇ¾î ÀÖ´ÂÁö È®ÀÎÇÏ¸é¼­ °ü¸®ÀÚ°¡ ¾Æ´Ñ°æ¿ì °Ë»öÀ» ¸øÇÏ°Ô ÇÏ¸ç, Çã°¡¹ŞÁö ¾ÊÀº µ¥ÀÌÅÍÀÇ Á¢±ÙÀ» ¹æÁöÇÑ´Ù. ÀÌ·Î½á µ¥ÀÌÅÍÀÇ ¹«°á¼º°ú Á¢±Ù±ÇÇÑÀ» º¸È£ÇÔ.
// strstr ÇÔ¼ö¸¦ »ç¿ëÇÏ¿© µ¥ÀÌÅÍÀÇ ÀÏºÎ¶óµµ °Ë»öÀÌ µÇ°Ô ÇÏ¿©, µ¥ÀÌÅÍÀÇ Á¢±Ù¼ºÀ» ³ôÀÌ°í ÀÏ°ü¼ºÀ» ÇØÄ¡Áö ¾Ê´Â´Ù.
// searching º¯¼ö¸¦ ÀÌ¿ëÇØ¼­ °Ë»ö °á°ú°¡ ÀÖ´ÂÁö¸¦ È®ÀÎÇÏ¸ç µ¥ÀÌÅÍÀÇ ÀÏ°ü¼ºÀ» À¯ÁöÇÑ´Ù.
void videosearch() { // ºñµğ¿À °Ë»ö ÇÔ¼ö
	char videoname[100]; // videonameÀ» 100byteÀÇ ¹è¿­·Î ¼±¾ğÇÑ ÀÌÀ¯´Â ³»°¡ ¹®ÀÚ³ª ¼ıÀÚ¸¦ ¾ó¸¶³ª ÀÔ·ÂÇÒÁö ¸ğ¸£±â ¶§¹®¿¡ 100byte·Î ¼³Á¤ÇÔ.
	int searching = 0; // searchingÀº 0À¸·Î ÃÊ±âÈ­¸¦ ½ÃÄÑ³õ°í °Ë»öÇÑ ³»¿ëÀÌ ÀÖÀ» ¶§ 1·Î º¯°æÇÏ±â À§¿¡¼­ 0À¸·Î ÁöÁ¤
	if (firstvideomanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ °Ë»öÀ» ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	while (1) { // while(1)·Î Ç×»ó ÂüÀ¸·Î ¸¸µç ÈÄ¿¡ ¸¶Áö¸·¿¡ break;¸¦ ÇÔ
		printf("°Ë»öÇÒ ºñµğ¿À¸¦ ÀÔ·ÂÇÏ¼¼¿ä(ºÎºĞ ¹®ÀÚ °Ë»ö°¡´É): ");
		scanf("%[^\n]", videoname); //  %[^\n]Àº °ø¹éÀ» Á¦¿ÜÇÏ´Â ¹®ÀÚ¿­ ÀÔ·Â
		getchar(); // getchar(); ·Î ÀÔ·Â ¹öÆÛ¸¦ Áö¿ò
		for (int i = 0; i < videosize; i++) {
			if (strstr(vod[i].videonumber, videoname)) { // ³»°¡ °Ë»öÇÑ ºÎºĞ ¹®ÀÚ¿­ÀÌ videonumber, Áï ºñµğ¿À °íÀ¯¹øÈ£¿¡ Æ÷ÇÔµÇ´ÂÁö¸¦ È®ÀÎÇÏ°í Æ÷ÇÔµÈ´Ù¸é Ãâ·ÂÇÔ.
				printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
				printf("ÀÌ¸§: %s\n", vod[i].name);
				printf("Àå¸£: %s\n", vod[i].genre);
				printf("°¨µ¶: %s\n", vod[i].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
				searching = 1;
			}
			else if (strstr(vod[i].name, videoname)) { // À§¿Í °°Àº ¿ø¸®·Î ÀÌ¸§¿¡¼­ ºÎºĞ ¹®ÀÚ¿­À» °Ë»öÇÔ.
				printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
				printf("ÀÌ¸§: %s\n", vod[i].name);
				printf("Àå¸£: %s\n", vod[i].genre);
				printf("°¨µ¶: %s\n", vod[i].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
				searching = 1;
			}
			else if (strstr(vod[i].genre, videoname)) { // Àå¸£¿¡¼­ ºÎºĞ ¹®ÀÚ¿­ °Ë»öÇÏ´Â °úÁ¤
				printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
				printf("ÀÌ¸§: %s\n", vod[i].name);
				printf("Àå¸£: %s\n", vod[i].genre);
				printf("°¨µ¶: %s\n", vod[i].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
				searching = 1;
			}
			else if (strstr(vod[i].director, videoname)) {
				printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
				printf("ÀÌ¸§: %s\n", vod[i].name);
				printf("Àå¸£: %s\n", vod[i].genre);
				printf("°¨µ¶: %s\n", vod[i].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
				searching = 1;
			}
			// ºñµğ¿À ±¸Á¶Ã¼¿¡´Â °íÀ¯¹øÈ£, ÀÌ¸§, Àå¸£, °¨µ¶, ´ë¿©ÇÑ È¸¿ø, ´ë¿© ¿©ºÎ°¡ Ãâ·ÂÀÌ µÇ¾úÁö¸¸ ºñµğ¿À °Ë»ö¿¡¼­´Â ÇÊ¼ö °úÁ¤Àº ¾Æ´Ñ °Í °°¾Æ Á¦¿ÜÇÔ.
		}
		if (searching == 0) { //  ¸¸¾à searchingÀÌ 0ÀÌ¶ó¸é ¾Õ¿¡¼­ ÃÊ±âÈ­ ÇÑ °ªÀÌ ±×´ë·Î ÀÖ´Â °ÍÀÌ¹Ç·Î °Ë»ö °á°ú°¡ ¾ø´Â °ÍÀÓ. ¿¹¿Ü Ã³¸® °úÁ¤
			printf("°Ë»öÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			break;
		}
		break;
	}
}

void membersearch() { //  È¸¿ø °Ë»ö ÇÔ¼ö
	char membername[100]; // ºñµğ¿À °Ë»ö ÇÔ¼ö¿Í °°Àº ¿ø¸®·Î ÄÚµå¸¦ ÀÛ¼ºÇÏ¿´À½.
	int searching = 0;
	if (firstmembermanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ °Ë»öÀ» ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	while (1) {
		printf("°Ë»öÇÒ È¸¿øÀ» ÀÔ·ÂÇÏ¼¼¿ä(ºÎºĞ ¹®ÀÚ °Ë»ö°¡´É): ");
		scanf("%[^\n]", membername);
		getchar();
		for (int i = 0; i < membersize; i++) {
			if (strstr(guest[i].number, membername)) {
				printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
				printf("id: %s\n", guest[i].id);
				printf("ÀÌ¸§: %s\n", guest[i].name);
				printf("ÀüÈ­¹øÈ£: %s\n", guest[i].number);
				printf("¼ºº°: %s\n", guest[i].gender);
				printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[i].rentcount);
				searching = 1;
			}
			else if (strstr(guest[i].name, membername)) {
				printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
				printf("id: %s\n", guest[i].id);
				printf("ÀÌ¸§: %s\n", guest[i].name);
				printf("ÀüÈ­¹øÈ£: %s\n", guest[i].number);
				printf("¼ºº°: %s\n", guest[i].gender);
				printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[i].rentcount);
				searching = 1;
			}
			else if (strstr(guest[i].number, membername)) {
				printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
				printf("id: %s\n", guest[i].id);
				printf("ÀÌ¸§: %s\n", guest[i].name);
				printf("ÀüÈ­¹øÈ£: %s\n", guest[i].number);
				printf("¼ºº°: %s\n", guest[i].gender);
				printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[i].rentcount);
				searching = 1;
			}
			else if (strstr(guest[i].gender, membername)) {
				printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
				printf("id: %s\n", guest[i].id);
				printf("ÀÌ¸§: %s\n", guest[i].name);
				printf("ÀüÈ­¹øÈ£: %s\n", guest[i].number);
				printf("¼ºº°: %s\n", guest[i].gender);
				printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[i].rentcount);
				searching = 1;
			}
		}
		if (searching == 0) { // È¸¿øÀÌ Á¸ÀçÇÏÁö ¾ÊÀ» ¶§ÀÇ ¿¹¿Ü Ã³¸®
			printf("°Ë»öÇÑ È¸¿øÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			break;
		}
		break;
	}
}
 // strcmp ÇÔ¼ö¸¦ »ç¿ëÇÏ¿© ÀÌ¸§À» ÀÔ·ÂÇÏ¿© Àß¸øµÈ ÀÔ·ÂÀÌ³ª Àß¸øµÈ µ¥ÀÌÅÍ°¡ ¹İ¿µÀÌ µÇÁö ¾Êµµ·Ï ÇÔ.
 // µ¿¸íÀÌÀÎÀ» Ã³¸®ÇÏ¿© µ¥ÀÌÅÍÀÇ Á¤È®¼ºÀ» ÁöÅ´
 // Æ¯Á¤ ¾ÆÀÌµğÀÇ È¸¿øÀÌ ºñµğ¿À¸¦ ´ë¿©ÇÏ¸é ºñµğ¿ÀÀÇ ´ë¿© °¡´É »óÅÂ¸¦ 0À¸·Î ¹Ù²ã¼­ ´ë¿©ºÒ°¡´É ÇÏ°Ô ¸¸µë, ÇÏ³ªÀÇ ºñµğ¿À°¡ Áßº¹À¸·Î ´ë¿©µÇÁö ¾Êµµ·Ï ÇÔ. 
 // ºñµğ¿ÀÀÇ ´ë¿©°¡´É ¿©ºÎ¸¦ È®ÀÎÇÏ¿© ´ë¿© °¡´ÉÇÑ ºñµğ¿À¸¸ ´ë¿©¸¦ ÇÒ ¼öÀÖµµ·Ï ÇÔÀ¸·Î½á ½Ã½ºÅÛÀÇ »óÅÂ¿Í ÀÏ°üµÈ ´ë¿©°¡ ÀÌ·ç¾î Áö°Ô ÇÔ.
 // ´ë¿©¸¦ ÇÒ ¶§ »ç¿ëÀÚ°¡ ¼±ÅÃÀ» ÇÔÀ¸·Î½á ¼±ÅÃ °úÁ¤À» ¸íÈ®ÇÏ°Ô Ã³¸®ÇÏ¿© µ¥ÀÌÅÍÀÇ ÀÏ°ü¼ºÀ» À¯ÁöÇÔ
void rent() { // ºñµğ¿À ´ë¿© ÇÔ¼ö
	char searchname[100]; // searchname¹è¿­Àº È¸¿ø ÀÌ¸§À» ÀÔ·ÂÇÑ °ªÀÌ µé¾î°¨. 100byte·Î ¼³Á¤ÇÑ ÀÌÀ¯´Â ¾ó¸¶³ª ÀÔ·ÂÇÒÁö Á¤ÇØÁöÁö ¾Ê¾Ò±â ‹š¹®ÀÓ.
	char rentname[100]; // rentname¹è¿­Àº ÇØ´ç ÀÌ¸§À¸·Î ´ë¿©ÇÏ´Â °ÍÀ» È®ÀÎÇÒ ¶§ µé¾î°¨. 100byteÀÇ ÀÌÀ¯´Â À§¿¡ ¼³¸íÇÔ.
	char rentid[100]; // rentid ¹è¿­Àº ´ë¿©¸¦ ÇÏ¸é¼­ id¸¦ ÀÔ·Â¹Ş¾Æ¼­ ´ë¿©¸¦ ÇÏ±â ¶§¹®¿¡ id¸¦ ÀÔ·Â ¹Ş´Â ¹è¿­ÀÓ. 
	char rentvideo[100]; // rentvideo ¹è¿­Àº ´ë¿© °úÁ¤¿¡¼­ ´ë¿©ÇÒ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·Â ¹ŞÀ» ¶§ »ç¿ëÇÔ.
	int searching = 0; // È¸¿øÀÌ Á¸ÀçÇÔÀ» Ã£±â À§ÇØ¼­ º¯¼ö¸¦ ÁöÁ¤ÇÔ
	int duplicate = 0; // µ¿¸íÀÌÀÎÀÌ ÀÖÀ» ¶§¸¦ Ã³¸® ÇÏ±â À§ÇØ¼­ º¯¼ö¸¦ ÁöÁ¤ÇÔ
	int idfound = 0; // id¸¦ Ã£¾ÒÀ» ¶§ 1·Î ¹Ù²Ù±â À§ÇØ¼­ 0À¸·Î ÃÊ±âÈ­¸¦ ½ÃÅ´.
	int memberindex = -1; // memberindex¸¦ -1·Î ÇØ³õÀº ÀÌÀ¯´Â 0À¸·Î ÇÏ¸é 0¹øÂ° ÀÎµ¦½º¿¡ Á¢±Ù ÇÒ ¼öµµ ÀÖ±â ¶§¹®¿¡ -1·Î ÁöÁ¤ÇÔ
	printf("È¸¿ø ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
	scanf("%[^\n]", searchname);
	getchar();
	for (int i = 0; i < Nummember; i++) {
		if (strcmp(guest[i].name, searchname) == 0) { // strcmpÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ ¹®ÀÚ¿­À» ºñ±³ÇÏ°í ³»°¡ ÀÔ·ÂÇÑ ÀÌ¸§°ú °°À¸¸Õ searchingÀ» 1·Î ¹Ù²Ş.
			searching = 1;
			break;
		}
	}
	if (searching == 0) { // ¸¸¾à searchingÀÌ 0ÀÌ¶ó¸é ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ±â ¶§¹®¿¡ Á¸ÀçÇÏÁö ¾Ê´Â´Ù´Â ¹®±¸¸¦ Ãâ·ÂÇÔ. ¿¹¿Ü Ã³¸® °úÁ¤
		printf("ÇØ´ç ÀÌ¸§ÀÇ È¸¿øÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
		return;
	}
	if (searching) { // ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ Á¸ÀçÇÒ ¶§ Á¶°Ç¹®ÀÌ ½ÇÇà‰Î
		printf("ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ Á¸ÀçÇÕ´Ï´Ù. ÇØ´ç ÀÌ¸§À¸·Î ´ë¿©ÇÏ½Ã°Ú½À´Ï±î?(1: ¿¹, 1ÀÌ¿ÜÀÇ ¹®ÀÚ¿­: ¾Æ´Ï¿À) ");
		scanf("%s", rentname);
		getchar();
		if (rentname[0] == '1') { // rentname[0]À¸·Î ÇÏ´Â ÀÌÀ¯´Â ¾Õ¿¡ ÀÖ´Â ¼ıÀÚ¸¸ ¹Ş±â À§ÇØ¼­ÀÌ´Ù.
			for (int i = 0; i < Nummember; i++) {
				if (strcmp(guest[i].name, searchname) == 0) {
					printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
					printf("id: %s\n", guest[i].id);
					printf("ÀÌ¸§: %s\n", guest[i].name);
					printf("ÀüÈ­¹øÈ£: %s\n", guest[i].number);
					printf("¼ºº°: %s\n", guest[i].gender);
					printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[i].rentcount);
					duplicate++;
					// µ¿¸íÀÌÀÎÀ» Ã£´Â °úÁ¤ ±×¸®°í Ã£¾Ò´Ù¸é ´ë¿©¸¦ id·Î ÇÏ±â ¶§¹®¿¡ id¸¦ Ã£±â À§ÇØ¼­ È¸¿ø Á¤º¸¸¦ Ãâ·ÂÇÔ.
				}
			}
			if (duplicate == 1) { // µ¿¸íÀÌÀÎÀÌ Á¸ÀçÇÏÁö ¾ÊÀ» ¶§
				printf("ºñµğ¿À¸¦ ´ë¿©ÇÒ ¾ÆÀÌµğ¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä: ");
				scanf("%s", rentid);
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].id, rentid) == 0) {
						idfound = 1;
						memberindex = i;
						break;
						// ´ë¿©ÇÒ ¾ÆÀÌµğ¸¦ ÀÔ·Â ¹Ş°í strcmp¸¦ ÀÌ¿ëÇØ¼­ ºñ±³ÇÑÈÄ °°´Ù¸é idfound¸¦ 1·Î ¹Ù²Ù°í memberindex = i·Î ÁöÁ¤
					}
				}
				if (idfound == 0) { // ¸¸¾à idfound°¡ 0ÀÌ¶ó¸é À§¿¡¼­ ¾ÆÀÌµğ¸¦ ¸øÃ£Àº°ÍÀÌ¹Ç·Î ¾ÆÀÌµğ°¡ Á¸ÀçÇÏÁö ¾Ê´Ù´Â ¹®±¸¿Í ÇÔ²² ¿¹¿Ü Ã³¸®¸¦ ÇÔ.
					printf("ÀÔ·ÂÇÑ ¾ÆÀÌµğ°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
					return;
				}
				printf("%s¾ÆÀÌµğÀÇ È¸¿øÀ¸·Î ºñµğ¿À¸¦ ´ë¿©ÇÏ°Ú½À´Ï´Ù.\n", rentid); // ¾ÆÀÌµğ°¡ Á¸ÀçÇÏ¸é Ãâ·Â‰Î
				int availablevideo = 0; // availablevideo º¯¼ö´Â ´ë¿© °¡´ÉÇÑ ºñµğ¿À¸¦ Ã£¾ÒÀ» ¶§¸¦ Ã³¸®ÇÏ±â À§ÇØ¼­ ¸¸µë.
				for (int i = 0; i < Numvideo; i++) {
					if (vod[i].rental == 1) {
						availablevideo++;
						break;
						// ¸¸¾à availablevideo°¡ 1ÀÌ»óÀÌ¸é ´ë¿©°¡ °¡´ÉÇÑ ºñµğ¿À°¡ ÀÖ´Â °ÍÀÓ.
					}
				}

				if (availablevideo == 0) {
					printf("´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
					return;
					// ¸¸¾à availablevideo°¡ 0ÀÌ¸é ´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸®¸¦ ÇÔ.
				}

				printf("´ë¿© °¡´ÉÇÑ ºñµğ¿À ¸ñ·Ï: \n"); // ´ë¿© °¡´ÉÇÑ ºñµğ¿À ¸ñ·ÏÀ» Ãâ·ÂÇØ¼­ ´ë¿©¸¦ ÇÒ ¶§ ºñµğ¿ÀÀÇ °íÀ¯ ¹øÈ£¸¦ ÀÔ·Â ¹ŞÀ» ¼ö ÀÖµµ·Ï ÇÔ.
				int available = 0; // º¯¼ö¸¦ ÁöÁ¤ÇÑ ÀÌÀ¯´Â ¹Ø¿¡¼­ ´ë¿© °¡´ÉÇÑ ºñµğ¿À¸¸ Ãâ·ÂÀÌ µÇ¾î¾ß ÇÏ±â ¶§¹®¿¡ ´ë¿© °¡´ÉÀÌ 1ÀÎ °Í¸¸ Ã£±â À§ÇØ¼­ º¯¼ö¸¦ ÁöÁ¤ÇÔ
				for (int i = 0; i < Numvideo; i++) {
					if (vod[i].rental == 1) {
						printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
						printf("ÀÌ¸§: %s\n", vod[i].name);
						printf("Àå¸£: %s\n", vod[i].genre);
						printf("°¨µ¶: %s\n", vod[i].director);
						printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
						printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
						available = 1;
						// ¸¸¾à ´ë¿© °¡´É ¿©ºÎ°¡ 1ÀÌ¶ó¸é Á¤º¸¸¦ Ãâ·ÂÇÏ°í availableÀ» 1·Î ¹Ù²Ş
					}
				}
				if (available == 0) {
					printf("´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ ¾ø½À´Ï´Ù.\n\n");
					return;
					// ¸¸¾à availableÀÌ 0ÀÌ¶ó¸é ´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
				}
				if (Numvideo == 0) {
					printf("ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
					return;
				}
				printf("ºô¸®½Ç ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", rentvideo);
				getchar();

				int videorent = 0; // ¹Ø¿¡¼­ ´ë¿©¸¦ ÇÒ ¶§ ´ë¿©¸¦ ÇßÀ¸¸é 1·Î ¹Ù²Ù±â À§ÇØ¼­ º¯¼ö¸¦ ÁöÁ¤ÇÔ.
				for (int i = 0; i < Numvideo; i++) {
					if (strcmp(vod[i].videonumber, rentvideo) == 0) {
						vod[i].rental = 0;
						printf("%s¹øÈ£ÀÇ ºñµğ¿À¸¦ ´ë¿©Çß½À´Ï´Ù.\n", rentvideo);
						strcpy(vod[i].rentmemberid, rentid);
						guest[memberindex].rentcount++;
						videorent = 1;
						break;
						// ¸¸¾à ´ë¿©ÇÒ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£°¡ ºñµğ¿À ¸ñ·Ï¿¡ Á¸Àç ÇÏ¸é ´ë¿©¸¦ ÇÏ°í strcpyÇÔ¼ö¸¦ÀÌ¿ëÇØ¼­ ºñµğ¿À ±¸Á¶Ã¼ ¾È¿¡ µé¾îÀÖ´Â ´ë¿©ÇÑ È¸¿ø id¿¡ ³ÖÀ½.
						// ºô¸° ºñµğ¿À °³¼ö¸¦ ÇÏ³ª ´Ã¸®°í À§¿¡¼­ ¼±¾ğÇÑ videorent¸¦ 1·Î ¹Ù²Ş
					}
				}
				if (videorent == 0) { // ¸¸¾à videorent°¡ 0ÀÌ¶ó¸é °Ë»öÇÑ °íÀ¯¹øÈ£ÀÇ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸®¸¦ ÇÔ.
					printf("°Ë»öÇÑ ¹øÈ£ÀÇ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
					return;
				}
			}
			if (duplicate > 1) {
				printf("°Ë»öÇÑ ÀÌ¸§ Áß¿¡¼­ Áßº¹µÈ ÀÌ¸§ÀÌ ÀÌ·¸°Ô ÀÖ½À´Ï´Ù.\n");
				printf("ºñµğ¿À¸¦ ´ë¿©ÇÒ ¾ÆÀÌµğ¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä: ");
				scanf("%s", rentid);
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].id , rentid) == 0) {
						idfound = 1;
						memberindex = i;
						break;
						// ´ë¿©ÇÒ ¾ÆÀÌµğ¸¦ ÀÔ·Â ¹Ş°í strcmp¸¦ ÀÌ¿ëÇØ¼­ ºñ±³ÇÑÈÄ °°´Ù¸é idfound¸¦ 1·Î ¹Ù²Ù°í memberindex = i·Î ÁöÁ¤
					}
				}
				if (idfound == 0) { // ¸¸¾à idfound°¡ 0ÀÌ¶ó¸é À§¿¡¼­ ¾ÆÀÌµğ¸¦ ¸øÃ£Àº°ÍÀÌ¹Ç·Î ¾ÆÀÌµğ°¡ Á¸ÀçÇÏÁö ¾Ê´Ù´Â ¹®±¸¿Í ÇÔ²² ¿¹¿Ü Ã³¸®¸¦ ÇÔ.
					printf("ÀÔ·ÂÇÑ ¾ÆÀÌµğ°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
					return;
				}
				printf("%s¾ÆÀÌµğÀÇ È¸¿øÀ¸·Î ºñµğ¿À¸¦ ´ë¿©ÇÏ°Ú½À´Ï´Ù.\n", rentid); // ¾ÆÀÌµğ°¡ Á¸ÀçÇÏ¸é Ãâ·Â‰Î
				int availablevideo = 0; // availablevideo º¯¼ö´Â ´ë¿© °¡´ÉÇÑ ºñµğ¿À¸¦ Ã£¾ÒÀ» ¶§¸¦ Ã³¸®ÇÏ±â À§ÇØ¼­ ¸¸µë.
				for (int i = 0; i < Numvideo; i++) {
					if (vod[i].rental == 1) {
						availablevideo++;
						break;
						// ¸¸¾à availablevideo°¡ 1ÀÌ»óÀÌ¸é ´ë¿©°¡ °¡´ÉÇÑ ºñµğ¿À°¡ ÀÖ´Â °ÍÀÓ.
					}
				}

				if (availablevideo == 0) { 
					printf("´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
					return;
					// ¸¸¾à availablevideo°¡ 0ÀÌ¸é ´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸®¸¦ ÇÔ.
				}

				printf("´ë¿© °¡´ÉÇÑ ºñµğ¿À ¸ñ·Ï: \n"); // ´ë¿© °¡´ÉÇÑ ºñµğ¿À ¸ñ·ÏÀ» Ãâ·ÂÇØ¼­ ´ë¿©¸¦ ÇÒ ¶§ ºñµğ¿ÀÀÇ °íÀ¯ ¹øÈ£¸¦ ÀÔ·Â ¹ŞÀ» ¼ö ÀÖµµ·Ï ÇÔ.
				int available = 0; // º¯¼ö¸¦ ÁöÁ¤ÇÑ ÀÌÀ¯´Â ¹Ø¿¡¼­ ´ë¿© °¡´ÉÇÑ ºñµğ¿À¸¸ Ãâ·ÂÀÌ µÇ¾î¾ß ÇÏ±â ¶§¹®¿¡ ´ë¿© °¡´ÉÀÌ 1ÀÎ °Í¸¸ Ã£±â À§ÇØ¼­ º¯¼ö¸¦ ÁöÁ¤ÇÔ
				for (int i = 0; i < Numvideo; i++) {
					if (vod[i].rental == 1) {
						printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
						printf("ÀÌ¸§: %s\n", vod[i].name);
						printf("Àå¸£: %s\n", vod[i].genre);
						printf("°¨µ¶: %s\n", vod[i].director);
						printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
						printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
						available = 1;
						// ¸¸¾à ´ë¿© °¡´É ¿©ºÎ°¡ 1ÀÌ¶ó¸é Á¤º¸¸¦ Ãâ·ÂÇÏ°í availableÀ» 1·Î ¹Ù²Ş
					}
				}
				if (available == 0) {
					printf("´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ ¾ø½À´Ï´Ù.\n\n");
					return;
					// ¸¸¾à availableÀÌ 0ÀÌ¶ó¸é ´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
				}
				if (Numvideo == 0) {
					printf("ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
					return;
				}
				printf("ºô¸®½Ç ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", rentvideo);
				getchar();

				int videorent = 0; // ¹Ø¿¡¼­ ´ë¿©¸¦ ÇÒ ¶§ ´ë¿©¸¦ ÇßÀ¸¸é 1·Î ¹Ù²Ù±â À§ÇØ¼­ º¯¼ö¸¦ ÁöÁ¤ÇÔ.
				for (int i = 0; i < Numvideo; i++) {
					if (strcmp(vod[i].videonumber, rentvideo) == 0) {
						vod[i].rental = 0;
						printf("%s¹øÈ£ÀÇ ºñµğ¿À¸¦ ´ë¿©Çß½À´Ï´Ù.\n", rentvideo);
						strcpy(vod[i].rentmemberid, rentid);
						guest[memberindex].rentcount++;
						videorent = 1;
						break;
						// ¸¸¾à ´ë¿©ÇÒ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£°¡ ºñµğ¿À ¸ñ·Ï¿¡ Á¸Àç ÇÏ¸é ´ë¿©¸¦ ÇÏ°í strcpyÇÔ¼ö¸¦ÀÌ¿ëÇØ¼­ ºñµğ¿À ±¸Á¶Ã¼ ¾È¿¡ µé¾îÀÖ´Â ´ë¿©ÇÑ È¸¿ø id¿¡ ³ÖÀ½.
						// ºô¸° ºñµğ¿À °³¼ö¸¦ ÇÏ³ª ´Ã¸®°í À§¿¡¼­ ¼±¾ğÇÑ videorent¸¦ 1·Î ¹Ù²Ş
					}
				}
				if (videorent == 0) { // ¸¸¾à videorent°¡ 0ÀÌ¶ó¸é °Ë»öÇÑ °íÀ¯¹øÈ£ÀÇ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸®¸¦ ÇÔ.
					printf("°Ë»öÇÑ ¹øÈ£ÀÇ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
					return;
				}
			}
		}
		else { // ¸¸¾à 1ÀÌ ¾Æ´Ñ ´Ù¸¥ ¼ıÀÚ³ª ¹®ÀÚ¿­À» ÀÔ·ÂÇÏ¸é ´ë¿©ÇÏÁö ¾Ê´Â °úÁ¤.
			printf("ÀÔ·ÂÇÑ ÀÌ¸§À¸·Î ´ë¿©ÇÏÁö ¾Ê°Ú½À´Ï´Ù.\n\n");
			return;
		}
	}
}

int static videocompare(const void* first, const void* second)
{
	return strcmp(((video*)first)->name, ((video*)second)->name);
	// firstÆ÷ÀÎÅÍ¿¡ ÀÌ¸§, second Æ÷ÀÎÅÍ¿¡µµ ÀÌ¸§ÀÌ µé¾î°£ÈÄ qsortÇÔ¼ö¿¡¼­ ÀÌ¸§À» ±âÁØÀ¸·Î ¿À¸§Â÷¼ø Á¤·ÄÀ» ÇÔ.
}
// first´Â Ã¹¹øÂ° ¿ä¼Ò¸¦ °¡¸®Å³ Æ÷ÀÎÅÍ, second´Â µÎ¹øÂ° ¿ä¼Ò¸¦ °¡¸®Å³ Æ÷ÀÎÅÍ
// voidÀ» »ç¿ëÇÑ ÀÌÀ¯´Â qsort()ÇÔ¼ö¸¦ »ç¿ëÇÏ±â À§ÇØ¼­ qsort´Â ¾î¶² Å¸ÀÔÀÇ µ¥ÀÌÅÍµµ ¹ŞÀ» ¼ö ÀÖ¾î¾ß ÇÔ
// ÀúÀåµÈ ºñµğ¿À Á¤º¸¸¦ ÀÌ¸§ ±âÁØÀ¸·Î ¿À¸§Â÷¼ø Á¤·ÄÀ» ÇÏ±â À§ÇØ¼­ »ç¿ëÇÔ

// ºñµğ¿À¸¦ Ãâ·ÂÇÒ ¶§ °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï¶ó¸é Ãâ·ÂÀ» ¸øÇÏ°Ô ÇÔÀ¸·Î½á µ¥ÀÌÅÍÀÇ »ç¿ëÀ» ¸·À¸¸é¼­ µ¥ÀÌÅÍÀÇ ¹«°á¼ºÀ» º¸È£ÇÔ.
// ´ë¿© °¡´ÉÇÑ ºñµğ¿À¸¸ Ãâ·ÂÇÒ ¼ö ÀÖµµ·Ï ÇÔÀ¸·Î½á µ¥ÀÌÅÍÀÇ ÀÏ°ü¼ºÀ» À¯ÁöÇÔ.
void videoprint() { // ºñµğ¿À Ãâ·Â ÇÔ¼ö
	if (firstvideomanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ Ãâ·ÂÀ» ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	qsort(vod, Numvideo, sizeof(video), videocompare); // qsort ÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ ºñµğ¿ÀÀÇ Á¤º¸¸¦ ¿À¸§Â÷¼øÀ¸·Î Á¤·ÄÀ» ÇÔ
	if (Numvideo > 0) { // Numvideo°¡ ÇöÀç ºñµğ¿ÀÀÇ °³¼öÀÌ±â ¶§¹®¿¡ 0 ÀÌ»óÀÏ ¶§¸¸ Á¤º¸¸¦ Ãâ·ÂÇÔ.
		int available = 0; // º¯¼ö¸¦ ÁöÁ¤ÇÑ ÀÌÀ¯´Â ¹Ø¿¡¼­ ´ë¿© °¡´ÉÇÑ ºñµğ¿À¸¸ Ãâ·ÂÀÌ µÇ¾î¾ß ÇÏ±â ¶§¹®¿¡ ´ë¿© °¡´ÉÀÌ 1ÀÎ °Í¸¸ Ã£±â À§ÇØ¼­ º¯¼ö¸¦ ÁöÁ¤ÇÔ
		for (int i = 0; i < Numvideo; i++) {
			if (vod[i].rental == 1) {
				printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
				printf("ÀÌ¸§: %s\n", vod[i].name);
				printf("Àå¸£: %s\n", vod[i].genre);
				printf("°¨µ¶: %s\n", vod[i].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
				available = 1;
				// ¸¸¾à ´ë¿© °¡´É ¿©ºÎ°¡ 1ÀÌ¶ó¸é Á¤º¸¸¦ Ãâ·ÂÇÏ°í availableÀ» 1·Î ¹Ù²Ş
			}
		}
		if (available == 0) {
			printf("´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ ¾ø½À´Ï´Ù.\n\n");
			// ¸¸¾à availableÀÌ 0ÀÌ¶ó¸é ´ë¿© °¡´ÉÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
		}
	}
	else {
		printf("ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
		// ¸¸¾à Numvideo°¡ 0º¸´Ù Å©Áö ¾Ê´Ù¸é ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê´Â °Í.
	}
}

int static membercompare(const void* first, const void* second)
{
	return strcmp(((member*)first)->name, ((member*)second)->name);
	// firstÆ÷ÀÎÅÍ¿¡ ÀÌ¸§, second Æ÷ÀÎÅÍ¿¡µµ ÀÌ¸§ÀÌ µé¾î°£ÈÄ qsortÇÔ¼ö¿¡¼­ ÀÌ¸§À» ±âÁØÀ¸·Î ¿À¸§Â÷¼ø Á¤·ÄÀ» ÇÔ.
}
// first´Â Ã¹¹øÂ° ¿ä¼Ò¸¦ °¡¸®Å³ Æ÷ÀÎÅÍ, second´Â µÎ¹øÂ° ¿ä¼Ò¸¦ °¡¸®Å³ Æ÷ÀÎÅÍ
// voidÀ» »ç¿ëÇÑ ÀÌÀ¯´Â qsort()ÇÔ¼ö¸¦ »ç¿ëÇÏ±â À§ÇØ¼­ qsort´Â ¾î¶² Å¸ÀÔÀÇ µ¥ÀÌÅÍµµ ¹ŞÀ» ¼ö ÀÖ¾î¾ß ÇÔ
// ÀúÀåµÈ È¸¿ø Á¤º¸¸¦ ÀÌ¸§ ±âÁØÀ¸·Î ¿À¸§Â÷¼ø Á¤·ÄÀ» ÇÏ±â À§ÇØ¼­ »ç¿ëÇÔ

void memberprint() { // È¸¿ø Á¤º¸¸¦ Ãâ·ÂÇÏ´Â ÇÔ¼ö
	if (firstmembermanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ Ãâ·ÂÀ» ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	qsort(guest, Nummember, sizeof(member), membercompare); // qsortÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ È¸¿ø Á¤º¸¸¦ ¿À¸§Â÷¼ø Á¤·ÄÇÔ.
	if (Nummember > 0) { // ºñµğ¿À Ãâ·Â°ú °°Àº ¿ø¸®·Î ÄÚµå¸¦ ÀÛ¼ºÇÔ.
		for (int i = 0; i < Nummember; i++) {
			printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
			printf("id: %s\n", guest[i].id);
			printf("ÀÌ¸§: %s\n", guest[i].name);
			printf("ÀüÈ­¹øÈ£: %s\n", guest[i].number);
			printf("¼ºº°: %s\n", guest[i].gender);
			printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[i].rentcount);
		}
	}
	else {
		printf("È¸¿øÁ¤º¸°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
	}
}
// È¸¿øÁ¤º¸¸¦ Ãß°¡ÇÒ ‹šµµ ¸¶Âù°¡Áö·Î °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ñ ÀÌ»ó µ¥ÀÌÅÍ¿¡ Á¢±ÙÇÒ ¼ö ¾øµµ·Ï ¸¸µé¸é¼­ ¹«°á¼ºÀ» º¸È£ÇÔ
// È¸¿øÁ¤º¸¸¦ Ãß°¡ÇÒ ¶§, µ¿¸íÀÌÀÎÀÌ³ª, ÁöÁ¤µÈ ±æÀÌ¸¦ ÃÊ°úÇØ¼­ ÀÔ·ÂÇÏ°Å³ª, °°Àº ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÒ ¼ö ¾ø°Ô ÇÏ´Â µî, ÀÌ·¯ÇÑ ÀÛ¾÷¿¡¼­ µ¥ÀÌÅÍÀÇ ÀÏ°ü¼ºÀÌ À¯ÁöµÊ.
void memberadd() { // È¸¿ø Á¤º¸ Ãß°¡ ÇÔ¼ö.
	if (firstmembermanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ Ãß°¡¸¦ ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	if (Nummember >= membersize) {
		membersize = membersize * 2; // ¸¸¾à Nummember°¡ membersizeº¸´Ù Ä¿Áö¸é Å©±â¸¦ 2¹è ÇÑ ÈÄ¿¡ reallocÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ ¸Ş¸ğ¸®¸¦ ÀçÇÒ´ç ÇÔ.
		member* maxguest = (member*)realloc(guest, membersize * sizeof(member));
		if (maxguest == NULL) {
			printf("¸Ş¸ğ¸® ÇÒ´çÀ» ¸øÇß½À´Ï´Ù.\n");
			return 1;
			// ¸¸¾à À§¿¡¼­ ÁöÁ¤ÇÑ maxguest°¡ NULLÀÌ¶ó¸é ¸Ş¸ğ¸® ÇÒ´çÀ» ¸øÇÑ°ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸®¸¦ ÇÔ.
		}
		guest = maxguest; // ±× ÈÄ¿¡ ¸¸µé¾î ³õÀº guest¿¡ maxguest¸¦ ³ÖÀ½.
	}
	int repetition = 1; // while¹®À» ¹İº¹ÇÏ±â À§ÇØ¼­
	char samename[100]; // µ¿¸íÀÌÀÎÀ» Ã³¸®ÇÏ±â À§ÇØ¼­ 100byteÀÇ ¹è¿­À» ¼³Á¤ÇÔ.
	int duplicate = 0; // µ¿¸íÀÌÀÎÀ» Ã³¸® ÇÒ ¶§ »ç¿ëµÇ´Â º¯¼ö.
	randomid(guest[Nummember].id); // ¹Ø¿¡¼­ ¸¸µç id¸¦ ·£´ıÀ¸·Î ¸¸µå´Â ÇÔ¼öÀÓ.
	while (repetition) { // repetitionÀº ÇöÀç 1ÀÌ¹Ç·Î ÀÏ´Ü while¹®ÀÌ ½ÇÇà‰Î.
		printf("ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", guest[Nummember].name);
		repetition = 0; // ÀÌ¸§À» ÀÔ·Â ¹ŞÀº ÈÄ¿¡ ´õÀÌ»ó ÀÔ·ÂÀ» ¹ŞÁö ¾Ê±â À§ÇØ¼­ repetitionÀ» 0À¸·Î ¹Ù²Ş
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[Nummember].name, guest[i].name) == 0) {
				duplicate = 1; // µ¿¸íÀÌÀÎÀ» Ã³¸®ÇÏ´Â °úÁ¤.
			}
		}
		if (duplicate) {
			printf("°°Àº ÀÌ¸§ÀÇ »ç¶÷ÀÌ Á¸ÀçÇÕ´Ï´Ù.\n");
			printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷À¸·Î ÀúÀåÇÏ½Ã°Ú½À´Ï±î?(´Ù¸¥ »ç¶÷ÀÌ¸é 1 °°Àº »ç¶÷ÀÌ¸é 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¹®ÀÚ¿­) ");
			scanf("%s", samename);
			getchar();
			if (samename[0] == '1') {
				printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷À¸·Î Ãß°¡ÇÏ°Ú½À´Ï´Ù.\n");
				// 1À» ÀÔ·ÂÇÏ¸é °°Àº ÀÌ¸§ÀÇ ´Ù¸¥»ç¶÷, Áï µ¿¸íÀÌÀÎÀ¸·Î Á¤º¸¸¦ Ãß°¡ÇÔ.
			}
			else {
				printf("È¸¿ø Á¤º¸¸¦ Ãß°¡ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
				strcpy(guest[Nummember].id, "0");
				strcpy(guest[Nummember].name, "ÆRÆRÆRÆR");
				strcpy(guest[Nummember].number, "0");
				strcpy(guest[Nummember].gender, "0");
				guest[Nummember].rentcount = 0;
				return;
				// È¸¿ø Á¤º¸¸¦ Ãß°¡ÇÏÁö ¾Ê¾ÒÀ» ¶§ ÀÌ·±½ÄÀÇ ¹æ¹ıÀ» ¾´ ÀÌÀ¯´Â ¸Ç ¸¶Áö¸·¿¡¼­ Nummember++À» ÇÏ±â ¶§¹®¿¡ µµÁß¿¡ ÀÌ¸§À» ÀÔ·ÂÇÏ°í Ãë¼Ò¸¦ ÇÏ¸é
				// ¾²·¹±â °ªÀÌ »ı±â±â ¶§¹®¿¡ ¿À¸§Â÷¼øÀ» Á¤·Ä ÇßÀ» ¶§ÀÇ Á¦ÀÏ ¸¶Áö¸·ÀÎ 'ÆRÆRÆRÆR' À» ³Ö¾î¼­ °¡Àå ¹ØÀ¸·Î °¡°ÔÇÔÀ¸·Î½á ¾²·¹±â °ªÀ» Ãâ·ÂµÇÁö ¾Ê°ÔÇÔ.
			}
		}
		if (strlen(guest[Nummember].name) > 11) {
			printf("ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin);
			// ³»°¡ À§¿¡¼­ ÁöÁ¤ÇÑ ÀÌ¸§ÀÇ Å©±âº¸´Ù Å©°Ô ÀÔ·ÂÇÑ´Ù¸é ´Ù½Ã ÀÔ·ÂÀ» ¹Ş°Ô ÇÔ.
		}
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");

	repetition = 1; // ´Ù½Ã 1·Î ¸¸µé¾î¼­ ÀüÈ­¹øÈ£¸¦ Ãß°¡¹ŞÀ» ¼ö ÀÖµµ·Ï ÇÔ.
	while (repetition) { // ÀÌ¸§ Ãß°¡ °úÁ¤°ú °°Àº ¿ø¸®·Î ÄÚµå¸¦ ÀÛ¼ºÇÔ.
		printf("ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä(ex 010-1234-1234): ");
		scanf("%s", guest[Nummember].number);
		repetition = 0;
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[Nummember].number, guest[i].number) == 0) {
				printf("ÀüÈ­¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
				repetition = 1;
				break;
			}
		}
		if (strlen(guest[Nummember].number) > 13) {
			printf("ÀÔ·ÂÇÑ ÀüÈ­¹øÈ£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");

	repetition = 1;
	while (repetition) { // À§¿Í °°Àº °úÁ¤.
		printf("¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä(³²/¿©): ");
		scanf("%s", guest[Nummember].gender);
		getchar();
		repetition = 0;
		if (strlen(guest[Nummember].gender) > 3) {
			printf("ÀÔ·ÂÇÑ ¼ºº°ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");
	guest[Nummember].rentcount = 0; // ¸Ç Ã³À½¿¡ ´ë¿©ÇÑ ºñµğ¿À °³¼ö´Â 0ÀÌ±â ¶§¹®¿¡ 0À¸·Î ¼³Á¤ÇÔ.
	Nummember++; // Á¤º¸°¡ ´Ù ÀÔ·ÂÀÌ µÇ¾ú´Ù¸é Nummember++À» ÅëÇØ¼­ °³¼ö¸¦ ´Ã¸².
	printf("È¸¿ø Á¤º¸ »ı¼º ¿Ï·á\n\n");
	membersave(); // È¸¿ø Á¤º¸¸¦ ÀúÀåÇÔ.
}

void videoadd() { //  ºñµğ¿À Ãß°¡ ÇÔ¼ö
	if (firstvideomanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ Ãß°¡¸¦ ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	if (Numvideo >= videosize) { // À§¿¡¼­ È¸¿ø Á¤º¸ Ãß°¡ ÇÔ¼ö¿¡¼­ ¼³¸íÇÑ ³»¿ë°ú °°Àº ¿ø¸®·Î ÄÚµå¸¦ ÀÛ¼ºÇÔ.
		videosize = videosize * 2;
		video* maxvod = (video*)realloc(vod, videosize * sizeof(video));
		if (maxvod == NULL) {
			printf("¸Ş¸ğ¸® ÇÒ´çÀ» ¸øÇß½À´Ï´Ù.\n");
			exit(1);
		}
		vod = maxvod;
	}
	
	int repetition = 1;
	char samevideo[100];

	randomvideonumber(vod[Numvideo].videonumber);
	while (repetition) {
		printf("ºñµğ¿À Á¦¸ñÀ» ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", vod[Numvideo].name);
		getchar();
		repetition = 0;

		if (strlen(vod[Numvideo].name) > 61) {
			printf("ºñµğ¿ÀÀÇ Á¦¸ñÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");

	repetition = 1;
	while (repetition) {
		printf("ºñµğ¿ÀÀÇ Àå¸£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", vod[Numvideo].genre);
		getchar();
		repetition = 0;
		if (strlen(vod[Numvideo].genre) > 20) {
			printf("ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ Àå¸£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");

	repetition = 1;
	while (repetition) {
		printf("ºñµğ¿ÀÀÇ °¨µ¶À» ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", vod[Numvideo].director);
		getchar();
		repetition = 0;
		if (strlen(vod[Numvideo].director) > 12) {
			printf("ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ °¨µ¶ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n\n");
			repetition = 1;
			fflush(stdin);
		}
	}

	strcpy(vod[Numvideo].rentmemberid, "¾øÀ½"); // Ã³À½¿¡ ºñµğ¿À°¡ Ãß°¡µÇ¾úÀ» ¶§ ´ë¿©ÇÑ È¸¿øÀÌ ´ç¿¬È÷ ¾ø¾î¾ß ÇÏ¹Ç·Î ¾øÀ½À¸·Î ¹®ÀÚ¿­À» º¹»çÇØ¼­ ³Ö¾îµÒ.
	vod[Numvideo].rental = 1; // ´ë¿© °¡´É ¿©ºÎ¸¦ 1·Î ¸¸µë.

	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");
	Numvideo++;
	printf("ºñµğ¿À »ı¼º¿Ï·á\n\n");
	videosave(); // ºñµğ¿À¸¦ ÀúÀåÇÔ.
}

void randomid(char* id) { // È¸¿ø °íÀ¯ Á¤º¸¸¦ ·£´ıÀ¸·Î ¸¸µå´Â ÇÔ¼ö.
	int unique = 0;// Áßº¹À» °Ë»çÇÏ±â À§ÇÑ º¯¼ö
	srand((unsigned)time(NULL)); // ³­¼ö ÃÊ±âÈ­

	while (!unique) {
		for (int i = 0; i < 2; i++) {
			id[i] = 'A' + rand() % 26; // 0ºÎÅÍ 2±îÁö ¹İº¹ÇÏ¸é¼­ 2°³ÀÇ ´ë¹®ÀÚ ¾ËÆÄºªÀ» ¹ŞÀ» ¼ö ÀÖµµ·Ï ÇÏ¿´À¸¸ç ´ë¹®ÀÚÀÇ ÃÑ °³¼ö´Â 26°³ ÀÌ¹Ç·Î randÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ °íÀ¯ ¹øÈ£ »ı¼º.
		}
		for (int i = 2; i < 4; i++) { // À§¿¡¼­ 2°³ÀÇ ¾ËÆÄºªÀº ¸¸µé¾î Á³±â ¶§¹®¿¡ ¼ıÀÚ 2°³¸¦ ´õ Ãß°¡ÇÔ.
			id[i] = '0' + rand() % 10;
		}
		id[4] = '\0'; // ¹®ÀÚ¿­ÀÇ Á¦ÀÏ ¸¶Áö¸·Àº ³Î¹®ÀÚ°¡ µé¾î°¨.

		unique = 1;
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[i].id, id) == 0) {
				unique = 0;
				printf("°íÀ¯ ¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù.\n");
				break;
				// strcmp¸¦ ÀÌ¿ëÇØ¼­ °°ÀºÁö¸¦ ºñ±³ÇÏ°í °°À¸¸é unique¸¦ 0À¸·Î ¸¸µë 0ÀÌ¸é °°Àº °ÍÀÌ±â ¶§¹®¿¡ °°À» ¼ö ¾ø´Ù°í Ãâ·Â ‰Î. ¿¹¿Ü Ã³¸® °úÁ¤.
			}
		}
	}
	printf("È¸¿ø °íÀ¯ id°¡ ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");
}

void randomvideonumber(char* videonumber) { // ºñµğ¿À °íÀ¯¹øÈ£¸¦ ¸¸µå´Â ÇÔ¼ö
	int unique = 0; // È¸¿ø °íÀ¯ ¹øÈ£¸¦ ¸¸µå´Â ÇÔ¼ö¿Í °°Àº ¿ø¸®
	srand((unsigned)time(NULL)); // ³­¼ö ÃÊ±âÈ­

	while (!unique) {
		for (int i = 0; i < 2; i++) {
			videonumber[i] = '0' + rand() % 10;
		}
		for (int i = 2; i < 4; i++) {
			videonumber[i] = 'A' + rand() % 26;
		}
		videonumber[4] = '\0';

		unique = 1;
		for (int i = 0; i < Numvideo; i++) {
			if (strcmp(vod[i].videonumber, videonumber) == 0) {
				unique = 0;
				printf("°íÀ¯ ¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù.\n");
				break;
			}
		}
	}
	printf("ºñµğ¿À °íÀ¯ ¹øÈ£°¡ ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");
}

void videosave() { // ºñµğ¿À ÀúÀå ÇÔ¼ö.
	FILE* videobook; // ÆÄÀÏ Æ÷ÀÎÅÍ¸¦ videobookÀ¸·Î ¹ŞÀ½
	videobook = fopen("Video.txt", "w+"); // ÇöÀç µğ·ºÅä¸®¿¡ ÀÖ´Â Video.txt¿¡ ÀúÀåÀ» ÇÏ°í w+ ÀĞ±â¿Í ¾²±â ¸ğµå·Î ÆÄÀÏÀ» »ı¼º ÇÏ±â À§ÇÔ.
	if (videobook == NULL) {
		printf("ÆÄÀÏÀ» ¿­Áö ¸øÇß½À´Ï´Ù.");	
		exit(1);// ¸¸¾à videobook = NULLÀÌ¸é ÆÄÀÏÀÌ ¾È¿­¸®´Â °ÍÀÌ¹Ç·Î ¿¹¿ÜÃ³¸®¸¦ ÇÔ.
	}
	for (int i = 0; i < Numvideo; i++) {
		fprintf(videobook, " %s %s %s %s %s %d\n",
			vod[i].videonumber,
			vod[i].name,
			vod[i].genre,
			vod[i].director,
			vod[i].rentmemberid,
			vod[i].rental);
	} //fprintf°¡ ÆÄÀÏ¿¡ Ãâ·ÂÀ» ÇÏ´Â °ÍÀÌ±â ¶§¹®¿¡ ºñµğ¿À Á¤º¸¿¡ ÀÖ´Â videonumber, name, genre, director, rentmemberid, rentalÀ» °¢ ÀÎµ¦½º¿¡ ¸Â°Ô ÆÄÀÏ¾È¿¡ Ãâ·ÂÀ» ÇÏ°í ÀúÀåÀ» ÇÔ.
	fclose(videobook); // ÆÄÀÏÀ» ´İÀ½.
	printf("ºñµğ¿À°¡ ÆÄÀÏ¿¡ ÀúÀåµÇ¾ú½À´Ï´Ù.\n\n");
}

void membersave() { // ºñµğ¿À ÀúÀå°ú °°Àº ¿ø¸®·Î ÀÛ¼ºÇÔ.
	FILE* memberbook; 
	memberbook = fopen("Member.txt", "w+"); 
	if (memberbook == NULL) {
		printf("ÆÄÀÏÀ» ¿­Áö ¸øÇß½À´Ï´Ù.");
		exit(1);
	}
	for (int i = 0; i < Nummember; i++) {
		fprintf(memberbook, " %s %s %s %s %d\n",
			guest[i].id,
			guest[i].name,
			guest[i].number,
			guest[i].gender,
			guest[i].rentcount);
	} 
	fclose(memberbook);
	printf("È¸¿øÁ¤º¸°¡ ÆÄÀÏ¿¡ ÀúÀåµÇ¾ú½À´Ï´Ù.\n\n");
}

void videoload() { // ºñµğ¿À¸¦ ºÒ·¯¿À´Â ÇÔ¼ö.
	FILE* videobook = fopen("Video.txt", "r+"); // videobookÀ» r+·Î ÀĞ±â¿Í ¾²±â ¸ğµå°¡ °¡´ÉÇÏµµ·Ï ÆÄÀÏÀ» ¿°
	if (videobook == NULL) { // videobookÀÌ NULLÀÌ¸é ÆÄÀÏÀ» ¿­Áö ¸øÇÑ°ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
		printf("ÆÄÀÏÀ» ¿­Áö ¸øÇß½À´Ï´Ù.");
		exit(1);
	}

	while (fscanf(videobook, " %s %s %s %s %s %d\n",
		vod[Numvideo].videonumber,
		vod[Numvideo].name,
		vod[Numvideo].genre,
		vod[Numvideo].director,
		vod[Numvideo].rentmemberid,
		&vod[Numvideo].rental) == 6) {  // fscanf¸¦ ÀÌ¿ëÇØ¼­ ÆÄÀÏÀ» ÀĞ°í 6°³°¡ ¼º°øÀûÀ¸·Î ÀĞÇû´ÂÁö È®ÀÎÇÔ.

		Numvideo++; // ÀĞÀº ÈÄ NumvideoÀ» Áõ°¡½ÃÄÑ ¿¬¶ôÃ³ÀÇ °³¼ö¸¦ ´Ã¸²

		// Numvideo°¡ videosize¸¦ ÃÊ°úÇÏ¸é Å©±â¸¦ Á¶Á¤ÇÏ°í ¸Ş¸ğ¸®¸¦ Àç ÇÒ´çÇÔ.
		if (Numvideo >= videosize) {
			videosize = videosize * 2;  // Å©±â¸¦ µÎ ¹è·Î Áõ°¡
			video* temp = (video*)realloc(vod, videosize * sizeof(video));
			if (temp == NULL) {  // temp°¡ NULLÀÌÃ ÀçÇÒ´çÀ» ¸øÇÑ °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
				printf("¸Ş¸ğ¸® ÀçÇÒ´ç ½ÇÆĞ\n");
				fclose(videobook); // ÆÄÀÏ ´İ±â
				exit(1);
			}
			vod = temp; // ÀçÇÒ´çÀ» ¼º°øÇÏ¸é temp¸¦ vod·Î ¸¸µë.
		}
	}

	fclose(videobook); // ÆÄÀÏÀ» ´İÀ½.
}


void memberload() { // ºñµğ¿À¸¦ ºÒ·¯¿À´Â ÇÔ¼ö¿Í °°Àº ¿ø¸®
	FILE* memberbook = fopen("Member.txt", "r+");
	if (memberbook == NULL) {
		printf("ÆÄÀÏÀ» ¿­Áö ¸øÇß½À´Ï´Ù.");
		exit(1);
	}

	while (fscanf(memberbook, " %s %s %s %s %d\n",
		guest[Nummember].id,
		guest[Nummember].name,
		guest[Nummember].number,
		guest[Nummember].gender,
		&guest[Nummember].rentcount) == 5) {

		Nummember++; 

		if (Nummember >= membersize) {
			membersize = membersize * 2; 	
			member* temp = (member*)realloc(guest, membersize * sizeof(member));
			if (temp == NULL) { 
				printf("¸Ş¸ğ¸® ÀçÇÒ´ç ½ÇÆĞ\n");
				fclose(memberbook); 
				exit(1);
			}
			guest = temp; 
		}
	}

	fclose(memberbook); 
}

void videoreturn() { // ºñµğ¿À¸¦ ¹İ³³ÇÏ´Â ÇÔ¼ö
	char searchname[100]; // ÀÌ¸§À» ÀÔ·Â¹ŞÀ» ¶§ »ç¿ëÇÏ´Â ¹è¿­
	char returnvideo[100]; // ¹İ³³ÇÒ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·Â¹ŞÀ» ¶§ »ç¿ëÇÏ´Â º¯¼ö
	char id[100]; // µ¿¸íÀÌÀÎÀÌ Á¸ÀçÇÒ ¶§ È¸¿øÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·Â¹Ş±â À§ÇØ »ç¿ëÇÏ´Â º¯¼ö
	int duplicate = 0; // µ¿¸íÀÌÀÎÀÌ Á¸ÀçÇÒ ¶§ Ã³¸®ÇÏ±â À§ÇÑ º¯¼ö
	int memberindex = -1; // memberindex¸¦ -1·Î ¼³Á¤ÇÑ ÀÌÀ¯´Â 0À¸·Î ÇÏ¸é 0À¸·Î Àß¸ø Á¢±ÙÇÒ ¼ö ÀÖ±â ¶§¹®.
	int rentfound = 0; // ÀÔ·ÂÇÑ È¸¿øÀÌ ´ë¿©ÇÑ ºñµğ¿À°¡ ÀÖÀ» ¶§ Ã¼Å©ÇÏ´Â º¯¼ö
	printf("È¸¿ø ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
	scanf("%[^\n]", searchname);
	getchar();

	for (int i = 0; i < Nummember; i++) { // ³»°¡ ÀÔ·ÂÇÑ ÀÌ¸§°ú Á¤º¸ÀÇ ÀÌ¸§ÀÌ °°´Ù¸é Á¤º¸¸¦ Ãâ·ÂÇÔ.
		if (strcmp(guest[i].name, searchname) == 0) {
			printf("id: %s\n", guest[i].id);
			printf("ÀÌ¸§: %s\n", guest[i].name);
			printf("ÀüÈ­¹øÈ£: %s\n", guest[i].number);
			printf("¼ºº°: %s\n", guest[i].gender);
			printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[i].rentcount);
			duplicate++; // duplicate¸¦ ´Ã¸®¸é¼­ µ¿¸íÀÌÀÎÀÇ °³¼ö¸¦ Ã£À½.
			if (duplicate == 1) { // ¸¸¾à duplicate°¡ 1ÀÌ¶ó¸é µ¿¸íÀÌÀÎÀÌ ¾ø´Â °ÍÀÌ¹Ç·Î memberindex¸¦ i·Î ¼³Á¤ÇÏ°í ¹®ÀÚ¿­À» º¹»çÇØ¼­ id¿¡ ÇØ´ç È¸¿øÀÇ id¸¦ ³ÖÀ½.
				memberindex = i;
				strcpy(id, guest[i].id);
			}
		}
	}
	if (duplicate == 0) { // ¸¸¾à duplicate°¡ 0ÀÌ¶ó¸é ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
		printf("ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
		return;
	}
	if (duplicate > 1) { // µ¿¸íÀÌÀÎÀÌ Á¸Àç ÇÒ¶§.
		printf("°°Àº ÀÌ¸§ÀÇ È¸¿øÀÌ Á¸ÀçÇÕ´Ï´Ù.\n");
		printf("È¸¿øÀÇ id¸¦ ÀÔ·ÂÇÏ¿© ¹İ³³À» ÁøÇàÇÏ°Ú½À´Ï´Ù.\n");
		printf("È¸¿ø id¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%[^\n]", id);
		getchar();
		memberindex = -1;
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[i].id, id) == 0) {
				strcpy(id, guest[i].id);
				memberindex = i;
				break;
				// ¸¸¾à ÀÔ·ÂÇÑ id¿Í È¸¿øÁ¤º¸ÀÇ ¾ÆÀÌµğ°¡ °°´Ù¸é ÀÔ·ÂÇÑ ¾ÆÀÌµğ¸¦ id¿¡ º¹»çÇÑ ÈÄ memberindex¸¦ i·Î ¹Ù²Ş.
			}
		}
		if (memberindex == -1) { // ¸¸¾à memberindex°¡ -1ÀÌ¸é ÀÔ·ÂÇÑ idÀÇ È¸¿øÀÌ Á¸ÀçÇÏÁö ¾Ê´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
			printf("ÀÔ·ÂÇÑ id¸¦ °¡Áø È¸¿øÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			return;
		}
	}
	if (guest[memberindex].rentcount == 0) { // rentcount°¡ 0ÀÌ¸é ´ë¿©ÇÑ ºñµğ¿À°¡ ¾ø´Â °ÍÀÌ¹Ç·Î ¹İ³³À» ÇÒ ¼ö°¡ ¾øÀ½.
		printf("´ë¿©ÇÑ ºñµğ¿À°¡ ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	printf("%s¾ÆÀÌµğÀÇ È¸¿øÀÌ ´ë¿© ÁßÀÎ ºñµğ¿À ¸ñ·Ï.\n\n", guest[memberindex]); // ÀÔ·ÂÇÑ ¾ÆÀÌµğÀÇ È¸¿øÀÌ ´ë¿©ÁßÀÎ ºñµğ¿À ¸ñ·ÏÀ» Ãâ·ÂÇÏ¿© °íÀ¯¹øÈ£¸¦ È®ÀÎÇÔ.
	for (int i = 0; i < Numvideo; i++) {
		if (vod[i].rental == 0 && strcmp(vod[i].rentmemberid, id) == 0) {
			printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
			printf("ÀÌ¸§: %s\n", vod[i].name);
			printf("Àå¸£: %s\n", vod[i].genre);
			printf("°¨µ¶: %s\n", vod[i].director);
			printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
			printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
			rentfound = 1;
			// rentfound¸¦ 1·Î ¸¸µé¾î¼­ Ã£¾ÒÀ» ¶§¸¦ Ã³¸®ÇÔ.
		}
	}
	if (rentfound == 0) { // ¸¸¾à rentfound°¡ 0ÀÌ¶ó¸é ´ë¿©ÁßÀÎ ºñµğ¿À ¸ñ·ÏÀÌ ¾ø´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
		printf("´ë¿© ÁßÀÎ ºñµğ¿À ¸ñ·ÏÀÌ ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	printf("¹İ³³ÇÒ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
	scanf("%[^\n]", returnvideo);
	getchar();

	int revideo = 0; // ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£°¡ Á¸ÀçÇÏ´ÂÁö È®ÀÎÇÏ±â À§ÇÑ º¯¼ö
	for (int i = 0; i < Numvideo; i++) {
		if (strcmp(vod[i].rentmemberid, id) == 0 && strcmp(vod[i].videonumber, returnvideo) == 0) {
			printf("%s°íÀ¯ ¹øÈ£ÀÇ ºñµğ¿À¸¦ ¹İ³³Çß½À´Ï´Ù.\n", returnvideo);
			vod[i].rental = 1;
			strcpy(vod[i].rentmemberid, "¾øÀ½");
			guest[memberindex].rentcount--;
			revideo = 1;
			break;
			// ¸¸¾à ÀÔ·ÂÇÑ ¹øÈ£ÀÇ °íÀ¯¹øÈ£¿Í ¹İ³³ÇÒ ºñµğ¿ÀÀÇ Á¦¸ñÀÌ °°´Ù¸é ¹İ³³À» ÁøÇàÇÏ°í ´Ù½Ã ºô¸° È¸¿ø id¸¦ ¾øÀ½À¸·Î ¸¸µé°í rentcount¸¦ ÇÏ³ª ÁÙÀÎÈÄ revideo¸¦ 1·Î ¸¸µë.
		}
	}
	if (revideo == 0) { // ¸¸¾à revideo°¡ 0ÀÌ¶ó¸é ÀÔ·ÂÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê°Å³ª ¹İ³³ÇÒ ¼ö ¾ø´Â °ÍÀÌ¹Ç·Î ¿¹¿Ü Ã³¸® °úÁ¤.
		printf("ÀÔ·ÂÇÑ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê°Å³ª ¹İ³³ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
}

void memberdelete() { // È¸¿øÀ» Á¦°ÅÇÏ´Â ÇÔ¼ö.
	if (firstmembermanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ »èÁ¦¸¦ ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	char deleteid[100]; // deleteid´Â Á¦°ÅÇÒ ¾ÆÀÌµğ¸¦ ÀÔ·Â¹ŞÀ» ¶§ »ç¿ëÇÏ´Â º¯¼ö.
	char select[100]; // select¶ó´Â º¯¼ö·Î ¹®ÀÚ¿­ ¹è¿­À» 100byte¸¸Å­ÀÇ Å©±â·Î ¹Ş¾Æ¼­ ³»°¡ ¹øÈ£¸¦ ÀÔ·ÂÇÒ ¶§ ¼ıÀÚ¸¸ÀÌ ¾Æ´Ñ ¹®ÀÚ·Îµµ ÀÔ·ÂÀ» °¡´ÉÇÏ°Ô ÇÔ
	char really[100]; // À§¿Í °°Àº ÀÌÀ¯
	while (1) {
		printf("1. È¸¿ø Á¤º¸ ÀüÃ¼»èÁ¦ \n");
		printf("2. È¸¿ø Á¤º¸ ¼±ÅÃ»èÁ¦ \n");
		printf("¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%[^\n]", select);
		getchar();
		if (Nummember == 0) { // ¸¸¾à Nummmember°¡ 0ÀÌ¶ó¸é È¸¿øÁ¤º¸°¡ ¾ø´Â °ÍÀÌ¹Ç·Î È¸¿ø Á¤º¸°¡ Á¸ÀçÇÏÁö ¾Ê´Â´Ù´Â ¹®±¸¸¦ Ãâ·ÂÇÏ°Ô ÇÔ. ¿¹¿Ü Ã³¸® °úÁ¤.
			printf("È¸¿øÁ¤º¸°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			return;
		}
		switch (select[0]) {
		case '1':
			for (int i = 0; i < Nummember; i++) {
				if (guest[i].rentcount > 0) {
					printf("%sÀÌ¸§ÀÇ È¸¿øÀÌ ºñµğ¿À¸¦ ´ë¿©ÁßÀÌ¹Ç·Î ÀüÃ¼ »èÁ¦¸¦ ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n", guest[i].name);
					return;
					// ¸¸¾à ÀüÃ¼ »èÁ¦¸¦ ÇÏ´õ¶óµµ ÇÑ¸íÀÌ¶óµµ ºñµğ¿À¸¦ ´ë¿©ÇÏ°í ÀÖ´Ù¸é »èÁ¦°¡ µÇ¸é ¾ÈµÇ±â ¶§¹®¿¡ ÀüÃ¼ »èÁ¦¸¦ ÇÒ ¼ö ¾øµµ·Ï ÇÔ. ¿¹¿Ü Ã³¸® °úÁ¤.
				}
			}
			printf("Á¤¸» »èÁ¦ÇÏ½Ã°Ú½À´Ï±î?(1À» ´©¸£¸é »èÁ¦ 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¼ıÀÚ, ¹®ÀÚ ÀÔ·Â½Ã »èÁ¦¾ÈÇÔ) ");
			scanf("%[^\n]", really);
			if (really[0] == '1') {
				Nummember = 0;
				printf("È¸¿ø Á¤º¸°¡ ÀüÃ¼ »èÁ¦µÇ¾ú½À´Ï´Ù.\n\n");
				return;
				// 1À» ÀÔ·ÂÇÏ¸é ÀüÃ¼»èÁ¦°¡ µÇ°í ±× ¿ÜÀÇ ¹®ÀÚ¸¦ ÀÔ·ÂÇÏ¸é ¸Ş´º·Î ³Ñ¾î°¨
			}
			else {
				printf("ÀüÃ¼»èÁ¦¸¦ ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
				return;
				// 1À» ÀÔ·ÂÇÏÁö ¾Ê¾Ò´Ù¸é ÀüÃ¼»èÁ¦¸¦ ÇÏÁö ¾Ê°í ¸Ş´º·Î ³Ñ¾î°¨.
			}
		case '2':
			memberprint(); // ¼±ÅÃ »èÁ¦¸¦ ÇÏ±â Àü¿¡ »èÁ¦ÇÒ È¸¿ø Á¤º¸ÀÇ id¸¦ ¾Ë°í ÀÖ¾î¾ß ÇÏ¹Ç·Î ¹Ì¸® È¸¿ø Á¤º¸¸¦ Ãâ·ÂÇÔ.
			printf("»èÁ¦ÇÒ È¸¿ø Á¤º¸ÀÇ id¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
			scanf("%[^\n]", deleteid);
			getchar();
			int found = -1; //  found´Â ÀÎµ¦½º¸¦ Ç¥ÇöÇÏ±â À§ÇØ¼­ »ç¿ëÇÑ º¯¼ö.
			for (int i = 0; i < Nummember; i++) {
				if (strcmp(guest[i].id, deleteid) == 0) {
					found = i;
					break;
					// ¸¸¾à ³»°¡ ÀÔ·ÂÇÑ id°¡ Á¸ÀçÇÑ´Ù¸é found¸¦ i·Î ¸¸µë.
				}
			}
			if (found == -1) { // found°¡ -1ÀÌ¶ó¸é ÀÔ·ÂÇÑ ¾ÆÀÌµğ°¡ Á¸ÀçÇÏÁö ¾Ê´Â °Í. ¿¹¿Ü Ã³¸® °úÁ¤.
				printf("ÀÔ·ÂÇÑ id°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
				return;
			}
			if (guest[found].rentcount > 0) { // ¸¸¾à ÀÔ·ÂÇÑ °íÀ¯¹øÈ£ÀÇ rentcount°¡ 0 ÀÌ»óÀÌ¶ó¸é ÇöÀç ´ë¿©ÁßÀÌ±â ¶§¹®¿¡ »èÁ¦¸¦ ¸øÇÏ°Ô ÇÔ. ¿¹¿Ü Ã³¸® °úÁ¤.
				printf("ÀÔ·ÂÇÑ °íÀ¯¹øÈ£´Â ´ë¿©ÁßÀÌ¹Ç·Î »èÁ¦ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
				return;
			}
			printf("id: % s\n", guest[found].id);
			printf("ÀÌ¸§: %s\n", guest[found].name);
			printf("ÀüÈ­¹øÈ£: %s\n", guest[found].number);
			printf("¼ºº°: %s\n\n", guest[found].gender);
			printf("Á¤¸» »èÁ¦ÇÏ½Ã°Ú½À´Ï±î?(1: »èÁ¦ 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¹®ÀÚ¿­: »èÁ¦ ¾ÈÇÔ): ");
			scanf("%[^\n]", really);
			getchar();
			// »èÁ¦ÇÒ Á¤º¸¸¦ Ãâ·ÂÇÏ°í Á¤¸» »èÁ¦¸¦ ÇÒ°ÍÀÎÁö¸¦ ÀÔ·Â ¹ŞÀ½.
			if (really[0] == '1') {
				for (int i = found; i < Nummember; i++) {
					guest[i] = guest[i + 1];
				}
				//really ¹è¿­¿¡¼­ Á¦ÀÏ ¾Õ¿¡ ÀÖ´Â°ÍÀÌ ¹®ÀÚ¿­ 1ÀÌ¸é ÇØ´ç ÀÎµ¦½º¸¦ »èÁ¦ÇÏ°í ¹è¿­ÀÌ ºñ±â ¶§¹®¿¡ µÚ¿¡ ÀÖ´Â ¹è¿­À» ¾ÕÀ¸·Î Ã¤¿ò
				printf("»èÁ¦ ¿Ï·á.\n\n");
				Nummember--;
				return;
			}
			else {
				printf("ÇØ´ç È¸¿ø Á¤º¸¸¦ »èÁ¦ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
				return;
			}
		default:
			printf("´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			return;
		}
	}
}

void videodelete() { // È¸¿ø »èÁ¦¿Í °°Àº ¿ø¸®·Î ÄÚµå¸¦ ÀÛ¼ºÇÔ.
	if (firstvideomanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ »èÁ¦¸¦ ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	char deletenumber[100];
	char choice[100];
	char really[100];
	while (1) {
		printf("1. ºñµğ¿À ÀüÃ¼ »èÁ¦\n");
		printf("2. ºñµğ¿À ¼±ÅÃ »èÁ¦\n");
		printf("¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%[^\n]", choice);
		getchar();
		if (Numvideo == 0) {
			printf("ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n");
			return;
		}

		switch (choice[0]) {
		case '1':
			for (int i = 0; i < Numvideo; i++) {
				if (vod[i].rental == 0) {
					printf("%sÁ¦¸ñÀÇ ºñµğ¿À°¡ ÇöÀç ´ë¿©ÁßÀÌ¹Ç·Î »èÁ¦ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n", vod[i].name);
					return;
				}
			}
			printf("Á¤¸» »èÁ¦ÇÏ½Ã°Ú½À´Ï±î?(1À» ´©¸£¸é »èÁ¦ 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¼ıÀÚ, ¹®ÀÚ ÀÔ·Â½Ã »èÁ¦¾ÈÇÔ) ");
			scanf("%[^\n]", really);
			if (really[0] == '1') {
				Numvideo = 0;
				printf("ºñµğ¿À°¡ ÀüÃ¼»èÁ¦µÇ¾ú½À´Ï´Ù.\n\n");
				return;
				// 1À» ÀÔ·ÂÇÏ¸é ÀüÃ¼»èÁ¦°¡ µÇ°í ±× ¿ÜÀÇ ¹®ÀÚ¸¦ ÀÔ·ÂÇÏ¸é ¸Ş´º·Î ³Ñ¾î°¨
			}
			else {
				printf("ÀüÃ¼»èÁ¦¸¦ ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
				return;
			}
		case '2':
			if (Numvideo > 0) {
				for (int i = 0; i < Numvideo; i++) {
					printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
					printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
					printf("Á¦¸ñ: %s\n", vod[i].name);
					printf("Àå¸£: %s\n", vod[i].genre);
					printf("°¨µ¶: %s\n", vod[i].director);
					printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
					printf("´ë¿©¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿© Áß): %d\n\n", vod[i].rental);
				}
			}
			else {
				printf("ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			}
			printf("»èÁ¦ÇÒ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
			scanf("%[^\n]", deletenumber);
			getchar();
			int found = -1;
			for (int i = 0; i < Numvideo; i++) {
				if (strcmp(vod[i].videonumber, deletenumber) == 0) {
					found = i;
					break;
				}
			}
			if (vod[found].rental == 0) {
				printf("ÇØ´ç ºñµğ¿À´Â ´ë¿©ÁßÀÌ¹Ç·Î »èÁ¦ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
				return;
			}
			if (found == -1) {
				printf("ÀÔ·ÂÇÑ °íÀ¯ ¹øÈ£°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
				return;
			}
			printf("°íÀ¯¹øÈ£: %s\n", vod[found].videonumber);
			printf("Á¦¸ñ: %s\n", vod[found].name);
			printf("Àå¸£: %s\n", vod[found].genre);
			printf("°¨µ¶: %s\n", vod[found].director);
			printf("´ë¿©¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿© Áß): %d\n\n", vod[found].rental);
			printf("Á¤¸» »èÁ¦ÇÏ½Ã°Ú½À´Ï±î?(1: »èÁ¦ 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¹®ÀÚ¿­: »èÁ¦ ¾ÈÇÔ): ");
			scanf("%[^\n]", really);
			getchar();
			if (really[0] == '1') {
				for (int i = found; i < Numvideo; i++) {
					vod[i] = vod[i + 1];
				}
				//really ¹è¿­¿¡¼­ Á¦ÀÏ ¾Õ¿¡ ÀÖ´Â°ÍÀÌ ¹®ÀÚ¿­ 1ÀÌ¸é ÇØ´ç ÀÎµ¦½º¸¦ »èÁ¦ÇÏ°í ¹è¿­ÀÌ ºñ±â ¶§¹®¿¡ µÚ¿¡ ÀÖ´Â ¹è¿­À» ¾ÕÀ¸·Î Ã¤¿ò
				printf("»èÁ¦¿Ï·á.\n\n");
				Numvideo--;
				return;
			}
			else {
				printf("ÇØ´ç ºñµğ¿À¸¦ »èÁ¦ÇÏÁö¾Ê¾Ò½À´Ï´Ù.\n\n");
				return;
			}
		default:
			printf("´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			return;
		}
	}
}

void videoedit() { // ºñµğ¿À ¼öÁ¤ÇÏ´Â ÇÔ¼ö
	if (firstvideomanager == 0) { // firstvideomanager´Â ÇöÀç ºñµğ¿ÀÀÇ °³¼ö°¡ 0ÀÏ ¶§´Â °ü¸®ÀÚ ¸ğµå¸¦ ¼³Á¤ÇÒ ¼ö ¾ø±â ¶§¹®¿¡ º¯¼ö¸¦ ¼³Á¤ÇØ¼­ °ü¸®ÀÚ ¸ğµå¸¦ ½ÇÇàÇÏ¸é 1, ¾Æ´Ï¸é 0À¸·Î ÇÏ°Ô ÇÔ.
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ ¼öÁ¤À» ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	char videonumber[100]; // videonumber¶ó´Â º¯¼ö¸¦ 100byte¹è¿­·Î ¼³Á¤ÇÑ ÀÌÀ¯´Â ÀÔ·ÂÇÑ °íÀ¯¹øÈ£°¡ µé¾î°¡´Â º¯¼öÀÎµ¥ ¾î¶² ¼ıÀÚ¿Í ¹®ÀÚ°¡ µé¾î°¥Áö ¸ğ¸£±â ¶§¹®
	int index = -1; // index¶ó´Â º¯¼ö¸¦ ¼³Á¤ÇÑ ÀÌÀ¯´Â ¹Ø¿¡¼­ Á¸ÀçÇÏ´ÂÁö È®ÀÎÇÒ ¶§ index = i¸¦ ÇÏ±â À§ÇÔ.
	while (1) {
		for (int i = 0; i < Numvideo; i++) {
			printf("°íÀ¯¹øÈ£: %s\n", vod[i].videonumber);
			printf("ÀÌ¸§: %s\n", vod[i].name);
			printf("Àå¸£: %s\n", vod[i].genre);
			printf("°¨µ¶: %s\n", vod[i].director);
			printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[i].rentmemberid);
			printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[i].rental);
		}
		if (Numvideo == 0) {
			printf("ºñµğ¿À Á¤º¸°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n");
			return;
		}
		// ¸ÕÀú ºñµğ¿À¸¦ ¼öÁ¤ÇÏ±â Àü¿¡ ÇöÀç °¡Áö°í ÀÖ´Â ºñµğ¿ÀÀÇ Á¤º¸¸¦ Ãâ·ÂÇÏ¿© °íÀ¯¹øÈ£¸¦ ÀÔ·Â ¹ŞÀ» ¼ö ÀÖµµ·Ï ÇÔ.
		printf("¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", videonumber);
		getchar();
		for (int i = 0; i < Numvideo; i++) {
			if (strcmp(vod[i].videonumber, videonumber) == 0) {
				index = i;
				break;
				// ¸¸¾à ºñµğ¿À Á¤º¸¾È¿¡ ³»°¡ ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ °íÀ¯¹øÈ£°¡ Á¸ÀçÇÑ´Ù¸é index = i·Î ¹Ù²Ş.
			}
		}
		if (index == -1) {
			printf("ÀÔ·ÂÇÑ °íÀ¯¹øÈ£ÀÇ ºñµğ¿À°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			return;
		}

		if (vod[index].rental == 1) {
			char editvideo[100]; // ¹øÈ£¸¦ ÀÔ·Â¹ŞÀ» ¶§ µé¾î°¡´Â º¯¼ö
			char editgenre[100]; // ºñµğ¿À Àå¸£¸¦ ¼öÁ¤ÇÒ ¶§ »ç¿ëÇÏ´Â º¯¼ö
			char editdirector[100]; // ºñµğ¿À °¨µ¶À» ¼öÁ¤ÇÒ ¶§ »ç¿ëÇÏ´Â º¯¼ö
			printf("°íÀ¯¹øÈ£: %s\n", vod[index].videonumber);
			printf("ÀÌ¸§: %s\n", vod[index].name);
			printf("Àå¸£: %s\n", vod[index].genre);
			printf("°¨µ¶: %s\n", vod[index].director);
			printf("1. ºñµğ¿À Á¦¸ñ ¼öÁ¤\n");
			printf("2. ºñµğ¿À Àå¸£ ¼öÁ¤\n");
			printf("3. ºñµğ¿À °¨µ¶ ¼öÁ¤\n");
			printf("4. ÀüÃ¼ ¼öÁ¤\n");
			printf("¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
			scanf("%s", editvideo);
			getchar();

			char editname[100];
			switch (editvideo[0]) { // editvideo[0]À¸·Î ÇÑ ÀÌÀ¯´Â ¹è¿­¿¡¼­ Á¦ÀÏ ¾Õ¿¡ ÀÖ´Â °ÍÀ» µû¿À±â À§ÇÔ.
			case '1':
				printf("¼öÁ¤ÇÒ ºñµğ¿À Á¦¸ñÀ» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", editname);
				getchar();
				if (strlen(editname) > 61) {
					printf("ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ Á¦¸ñÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
					// ¸¸¾à ÁöÁ¤ÇÑ Å©±âº¸´Ù Á¦¸ñÀ» ±æ°Ô ÇÑ´Ù¸é ¸ŞÀÎ¸Ş´º·Î µ¹¾Æ°¡°Ô ‰Î.
				}
				if (strcmp(vod[index].name, editname) == 0) {
					printf("¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ Á¦¸ñÀº °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
					// ¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ Á¦¸ñÀ» °°Áö ¾Ê°Ô ÇÑ ÀÌÀ¯´Â ¼öÁ¤ÀÌ±â ¶§¹®¿¡ °°Àº °ÍÀº ÀÖÀ» ¼ö ¾ø´Ù°í »ı°¢Çß±â ¶§¹®.
				}
				strcpy(vod[index].name, editname); // À§¿¡¼­ ¼öÁ¤À» ¾ÈÇßÀ» ¶§ ±× °ªÀÌ ±×´ë·Î ¼öÁ¤ÀÌ µÇ¾î¹ö¸®±â ¶§¹®¿¡ º¯¼ö¸¦ ÇÏ³ª ¸¸µé¾î¼­ ¼º°øÀûÀ¸·Î ¼öÁ¤ÀÌ µÇ¾ú´Ù¸é º¹»çÇØ¼­ ¼öÁ¤À» ÇÔ.
				printf("¼öÁ¤¿Ï·á.\n\n");
				printf("°íÀ¯¹øÈ£: %s\n", vod[index].videonumber);
				printf("ÀÌ¸§: %s\n", vod[index].name);
				printf("Àå¸£: %s\n", vod[index].genre);
				printf("°¨µ¶: %s\n", vod[index].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[index].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[index].rental);
				return;
			case '2':
				printf("¼öÁ¤ÇÒ ºñµğ¿À Àå¸£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: "); // À§¿Í °°Àº °³³äÀ¸·Î ÀÛ¼ºµÈ ÄÚµå
				scanf("%s", editgenre);
				getchar();
				if (strlen(editgenre) > 20) {
					printf("ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ Àå¸£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä\n");
					fflush(stdin);
					return;
				}
				if (strcmp(vod[index].genre, editgenre) == 0) {
					printf("¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ Àå¸£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				strcpy(vod[index].genre, editgenre);
				printf("¼öÁ¤¿Ï·á.\n\n");
				printf("°íÀ¯¹øÈ£: %s\n", vod[index].videonumber);
				printf("ÀÌ¸§: %s\n", vod[index].name);
				printf("Àå¸£: %s\n", vod[index].genre);
				printf("°¨µ¶: %s\n", vod[index].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[index].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[index].rental);
				return;
			case '3':
				printf("¼öÁ¤ÇÒ ºñµğ¿À °¨µ¶À» ÀÔ·ÂÇÏ¼¼¿ä: "); // À§¿Í °°Àº °³³äÀ¸·Î ÀÛ¼ºµÈ ÄÚµå
				scanf("%s", editdirector);
				getchar();
				if (strlen(editdirector) > 12) {
					printf("ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ °¨µ¶ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				if (strcmp(vod[index].director, editdirector) == 0) {
					printf("¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ °¨µ¶Àº °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				strcpy(vod[index].director, editdirector);
				printf("¼öÁ¤¿Ï·á.\n\n");
				printf("°íÀ¯¹øÈ£: %s\n", vod[index].videonumber);
				printf("ÀÌ¸§: %s\n", vod[index].name);
				printf("Àå¸£: %s\n", vod[index].genre);
				printf("°¨µ¶: %s\n", vod[index].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[index].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[index].rental);
				return;
			case '4':
				printf("¼öÁ¤ÇÒ ºñµğ¿À Á¦¸ñÀ» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", editname);
				getchar();
				if (strlen(editname) > 61) {
					printf("ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ Á¦¸ñÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
					// ¸¸¾à ÁöÁ¤ÇÑ Å©±âº¸´Ù Á¦¸ñÀ» ±æ°Ô ÇÑ´Ù¸é ¸ŞÀÎ¸Ş´º·Î µ¹¾Æ°¡°Ô ‰Î.
				}
				if (strcmp(vod[index].name, editname) == 0) {
					printf("¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ Á¦¸ñÀº °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
					// ¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ Á¦¸ñÀ» °°Áö ¾Ê°Ô ÇÑ ÀÌÀ¯´Â ¼öÁ¤ÀÌ±â ¶§¹®¿¡ °°Àº °ÍÀº ÀÖÀ» ¼ö ¾ø´Ù°í »ı°¢Çß±â ¶§¹®.
				}
				strcpy(vod[index].name, editname); // À§¿¡¼­ ¼öÁ¤À» ¾ÈÇßÀ» ¶§ ±× °ªÀÌ ±×´ë·Î ¼öÁ¤ÀÌ µÇ¾î¹ö¸®±â ¶§¹®¿¡ º¯¼ö¸¦ ÇÏ³ª ¸¸µé¾î¼­ ¼º°øÀûÀ¸·Î ¼öÁ¤ÀÌ µÇ¾ú´Ù¸é º¹»çÇØ¼­ ¼öÁ¤À» ÇÔ.
				printf("¼öÁ¤¿Ï·á.\n\n");

				printf("¼öÁ¤ÇÒ ºñµğ¿À Àå¸£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: "); // À§¿Í °°Àº °³³äÀ¸·Î ÀÛ¼ºµÈ ÄÚµå
				scanf("%s", editgenre);
				getchar();
				if (strlen(editgenre) > 20) {
					printf("ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ Àå¸£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä\n");
					fflush(stdin);
					return;
				}
				if (strcmp(vod[index].genre, editgenre) == 0) {
					printf("¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ Àå¸£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				strcpy(vod[index].genre, editgenre);
				printf("¼öÁ¤¿Ï·á.\n\n");
				printf("°íÀ¯¹øÈ£: %s\n", vod[index].videonumber);

				printf("¼öÁ¤ÇÒ ºñµğ¿À °¨µ¶À» ÀÔ·ÂÇÏ¼¼¿ä: "); // À§¿Í °°Àº °³³äÀ¸·Î ÀÛ¼ºµÈ ÄÚµå
				scanf("%s", editdirector);
				getchar();
				if (strlen(editdirector) > 12) {
					printf("ÀÔ·ÂÇÑ ºñµğ¿ÀÀÇ °¨µ¶ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				if (strcmp(vod[index].director, editdirector) == 0) {
					printf("¼öÁ¤ÇÒ ºñµğ¿ÀÀÇ °¨µ¶Àº °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				strcpy(vod[index].director, editdirector);
				printf("¼öÁ¤¿Ï·á.\n\n");
				printf("°íÀ¯¹øÈ£: %s\n", vod[index].videonumber);
				printf("ÀÌ¸§: %s\n", vod[index].name);
				printf("Àå¸£: %s\n", vod[index].genre);
				printf("°¨µ¶: %s\n", vod[index].director);
				printf("´ë¿©ÇÑ È¸¿ø id: %s\n", vod[index].rentmemberid);
				printf("´ë¿© ¿©ºÎ(1: ´ë¿© °¡´É, 0: ´ë¿©Áß): %d\n\n", vod[index].rental);
				return;
			default:
				printf("´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
				return;
			}
		}
		else {
			printf("ÇØ´ç ºñµğ¿À´Â ÇöÀç ´ë¿©ÁßÀÌ¹Ç·Î ¼öÁ¤ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
			return;
		}
		break;
	}
}


void memberedit() { // À§¿¡¼­ Â§ ºñµğ¿À ¼öÁ¤ ÇÔ¼ö¿Í °°Àº °³³äÀ» »ç¿ëÇÏ¿© ÄÚµå¸¦ Â«.
	if (firstvideomanager == 0) {
		printf("ÇöÀç °ü¸®ÀÚ ¸ğµå°¡ ¾Æ´Ï±â ¶§¹®¿¡ ¼öÁ¤À» ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
		return;
	}
	char memberid[100];
	int index = -1;
	while (1) {
		memberprint();
		printf("¼öÁ¤ÇÒ È¸¿øÁ¤º¸ÀÇ °íÀ¯¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", memberid);
		getchar();
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[i].id, memberid) == 0) {
				index = i;
				break;
			}
		}
		if (index == -1) {
			printf("ÀÔ·ÂÇÑ °íÀ¯¹øÈ£ÀÇ È¸¿øÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			return;
		}

		if (guest[index].rentcount == 0) {
			printf("id: % s\n", guest[index].id);
			printf("ÀÌ¸§: %s\n", guest[index].name);
			printf("ÀüÈ­¹øÈ£: %s\n", guest[index].number);
			printf("¼ºº°: %s\n\n", guest[index].gender);
			char editmember[100];
			printf("1. È¸¿ø ÀÌ¸§ ¼öÁ¤\n");
			printf("2. È¸¿ø ÀüÈ­¹øÈ£ ¼öÁ¤\n");
			printf("3. È¸¿ø ¼ºº° ¼öÁ¤\n");
			printf("4. ÀüÃ¼ ¼öÁ¤\n");
			printf("¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
			scanf("%s", editmember);
			getchar();

			char editname[100];
			char editnumber[100];
			char editgender[100];
			int duplicate = 0;
			char samename[100];

			switch (editmember[0])
			{
			case '1':
				printf("¼öÁ¤ÇÒ È¸¿ø ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", editname);
				getchar();
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].name, editname) == 0) {
						duplicate = 1;
						break;
					}
				}
				if (duplicate == 1) {
					printf("°°Àº ÀÌ¸§À» °¡Áø ´Ù¸¥ »ç¶÷ÀÌ ÀÖ½À´Ï´Ù.\n");
					printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷À¸·Î ¼öÁ¤ÇÏ½Ã°Ú½À´Ï±î?(1:¿¹ 1ÀÌ¿ÜÀÇ ¹®ÀÚ¿­:¾Æ´Ï¿À): ");
					scanf("%s", samename);
					getchar();
					if (samename[0] == '1') {
						printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷À¸·Î ¼öÁ¤ÇÏ°Ú½À´Ï´Ù.\n");
					}
					else {
						printf("¼öÁ¤ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
						return;
					}
				}
				else {
					printf("ÇØ´ç ÀÌ¸§À¸·Î ¼öÁ¤ÇÏ°Ú½À´Ï´Ù.\n");
				}
				if (strlen(editname) > 12) {
					printf("ÀÔ·ÂÇÑ ÀÌ¸§ÀÇ ±æÀÌ°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				if (strcmp(guest[index].name, editname) == 0) {
					printf("¼öÁ¤ÇÒ ÀÌ¸§Àº °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				strcpy(guest[index].name, editname);
				printf("¼öÁ¤ ¿Ï·á.\n");
				printf("id: %s\n", guest[index].id);
				printf("ÀÌ¸§: %s\n", guest[index].name);
				printf("ÀüÈ­¹øÈ£: %s\n", guest[index].number);
				printf("¼ºº°: %s\n", guest[index].gender);
				printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[index].rentcount);
				break;
			case '2':
				printf("¼öÁ¤ÇÒ ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", editnumber);
				getchar();
				if (strlen(editnumber) > 14) {
					printf("ÀÔ·ÂÇÑ ÀüÈ­¹øÈ£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].number, editnumber) == 0) {
						printf("¼öÁ¤ÇÒ ÀüÈ­¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
						fflush(stdin);
						return;
					}
				}
				strcpy(guest[index].number, editnumber);
				printf("¼öÁ¤ ¿Ï·á.\n");
				printf("id: %s\n", guest[index].id);
				printf("ÀÌ¸§: %s\n", guest[index].name);
				printf("ÀüÈ­¹øÈ£: %s\n", guest[index].number);
				printf("¼ºº°: %s\n", guest[index].gender);
				printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[index].rentcount);
				break;
			case '3':
				printf("¼öÁ¤ÇÒ ¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", editgender);
				getchar();
				if (strlen(editgender) > 3) {
					printf("ÀÔ·ÂÇÑ ¼ºº°ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].gender, editgender) == 0) {
						printf("¼öÁ¤ÇÒ ¼ºº°Àº °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
						fflush(stdin);
						return;
					}
				}
				strcpy(guest[index].gender, editgender);
				printf("¼öÁ¤ ¿Ï·á.\n");
				printf("id: %s\n", guest[index].id);
				printf("ÀÌ¸§: %s\n", guest[index].name);
				printf("ÀüÈ­¹øÈ£: %s\n", guest[index].number);
				printf("¼ºº°: %s\n", guest[index].gender);
				printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[index].rentcount);
				break;
			case '4':
				printf("¼öÁ¤ÇÒ È¸¿ø ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", editname);
				getchar();
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].name, editname) == 0) {
						duplicate = 1;
						break;
					}
				}
				if (duplicate == 1) {
					printf("°°Àº ÀÌ¸§À» °¡Áø ´Ù¸¥ »ç¶÷ÀÌ ÀÖ½À´Ï´Ù.\n");
					printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷À¸·Î ¼öÁ¤ÇÏ½Ã°Ú½À´Ï±î?(1:¿¹ 1ÀÌ¿ÜÀÇ ¹®ÀÚ¿­:¾Æ´Ï¿À): ");
					scanf("%s", samename);
					getchar();
					if (samename[0] == '1') {
						printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷À¸·Î ¼öÁ¤ÇÏ°Ú½À´Ï´Ù.\n");
					}
					else {
						printf("¼öÁ¤ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
						return;
					}
				}
				else {
					printf("ÇØ´ç ÀÌ¸§À¸·Î ¼öÁ¤ÇÏ°Ú½À´Ï´Ù.\n");
				}
				if (strlen(editname) > 12) {
					printf("ÀÔ·ÂÇÑ ÀÌ¸§ÀÇ ±æÀÌ°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				if (strcmp(guest[index].name, editname) == 0) {
					printf("¼öÁ¤ÇÒ ÀÌ¸§Àº °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				strcpy(guest[index].name, editname);
				printf("¼öÁ¤ ¿Ï·á.\n");

				printf("¼öÁ¤ÇÒ ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", editnumber);
				getchar();
				if (strlen(editnumber) > 14) {
					printf("ÀÔ·ÂÇÑ ÀüÈ­¹øÈ£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].number, editnumber) == 0) {
						printf("¼öÁ¤ÇÒ ÀüÈ­¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
						fflush(stdin);
						return;
					}
				}
				strcpy(guest[index].number, editnumber);
				printf("¼öÁ¤ ¿Ï·á.\n");

				printf("¼öÁ¤ÇÒ ¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", editgender);
				getchar();
				if (strlen(editgender) > 3) {
					printf("ÀÔ·ÂÇÑ ¼ºº°ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					fflush(stdin);
					return;
				}
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].gender, editgender) == 0) {
						printf("¼öÁ¤ÇÒ ¼ºº°Àº °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
						fflush(stdin);
						return;
					}
				}
				strcpy(guest[index].gender, editgender);
				printf("¼öÁ¤ ¿Ï·á.\n");
				printf("id: %s\n", guest[index].id);
				printf("ÀÌ¸§: %s\n", guest[index].name);
				printf("ÀüÈ­¹øÈ£: %s\n", guest[index].number);
				printf("¼ºº°: %s\n", guest[index].gender);
				printf("´ë¿©ÇÑ ºñµğ¿À °³¼ö: %d\n\n", guest[index].rentcount);
				break;
			default:
				printf("´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
				return;
			}
		}
		else {
			printf("ÇØ´ç È¸¿øÀº ÇöÀç ´ë¿©ÁßÀÎ ºñµğ¿À°¡ ÀÖ¾î ¼öÁ¤ÇÒ ¼ö ¾ø½À´Ï´Ù.\n\n");
			return;
		}
		break;
	}
}