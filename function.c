#define _CRT_SECURE_NO_WARNINGS
#include "numberbook.h"

void add()      // ¹øÈ£ Ãß°¡ÇÏ´Â ÇÔ¼ö
{
	if (n >= size) {
		size = size * 2;
		// size´Â À§¿¡¼­ Àü¿ªº¯¼ö·Î½á ¿¬¶ôÃ³ Å©±â¸¦ ÀÇ¹ÌÇÏ¸ç 1·Î ÁöÁ¤ÇØ µÎ¾úÀ½ Ã³À½ 1¹øÀº size°¡ 1ÀÌ±â ¶§¹®¿¡ ¿¬¶ôÃ³ÀÇ Å©±â°¡ 1ÀÌ¸ç
		// ¸ÕÀú ÇÏ³ªÀÇ ¿¬¶ôÃ³¸¦ ÀúÀåÇÑ´Ù. ±× ÀÌÈÄ 2¸¦ °öÇØ°¡¸é¼­ ¿¬¶ôÃ³ÀÇ Å©±â°¡ ÃÖ´ë°¡ µÉ¶§¸¶´Ù Ãß°¡ÇÒ ¼ö ÀÖ´Â ÀÎ¿øÀÇ °³¼ö¸¦ ´Ã¸°´Ù.
		address* maxtelephone = (address*)realloc(telephone, size * sizeof(address));
		// reallocÇÔ¼ö´Â ÇÒ´çÇÑ ¸Ş¸ğ¸®ÀÇ ºí·ÏÀÇ Å©±â¸¦ º¯°æÇÏ´Â ÇÔ¼ö·Î½á À§¿¡¼­ ÁöÁ¤ÇÑ telephoneÀÇ Å©±â¸¦ 
		// °è¼Ó ÀüÈ­¹øÈ£ºÎ¸¦ ÀúÀåÇÒ ¶§¸¶´Ù Å©±â°¡ ´ÙÇßÀ»¶§ µ¿Àû ¸Ş¸ğ¸®ÀÇ Å©±â¸¦ º¯°æÇÒ ¼ö ÀÖ°Ô ÇØÁØ´Ù.
		if (maxtelephone == NULL) {
			printf("¸Ş¸ğ¸® ÇÒ´çÀ» ¸øÇß½À´Ï´Ù\n");
			return;
		}
		// ¸¸¾à maxtelephoneÀÌ NULLÀÌ¸é ¸Ş¸ğ¸® ÇÒ´çÀ» ¸øÇÏ°Ô µÈ°ÍÀÌ¹Ç·Î if¹®À» »ç¿ëÇØ¼­ ¸Ş¸ğ¸® ÇÒ´ç¿¡¼­ ¹ß»ıÇÒ ¼ö ÀÖ´Â ¿¹¿Ü¸¦ Ã³¸®ÇÑ °ÍÀÌ´Ù.
		telephone = maxtelephone;
		// ³»°¡ À§¿¡¼­ maxtelephone¿¡ telephoneÀÇ µ¿Àû ¸Ş¸ğ¸®ÀÇ Å©±â°¡ ÃÖ´ë¿¡ ´ÙÇßÀ» ¶§ Å©±â¸¦ º¯°æÇÏ¿´±â ¶§¹®¿¡ ÀÌ ½ÄÀ» ºÙ¿©¼­ maxtelephoneÀÇ °ªÀ»
		// telephone¿¡ ³Ö´Â´Ù.
	}
	int i = 0;
	int repetition = 1;
	// while¹®¾È¿¡ µé¾î°¥ repetitionÀÌ¶ó´Â º¯¼ö¸¦ Á¤¼öÇüÀ¸·Î ÀÔ·ÂÀ» ¹ŞÀº°Í
	// intÇüÀ¸·Î ¹ŞÀº ÀÌÀ¯´Â while¹®À» »ç¿ëÇÒ ¶§ repetitionÀÇ ¼ıÀÚ¸¦ ¹Ù²Ù¸é¼­ ÁøÇàÀ» ÇÒ °ÍÀÌ±â ¶§¹®¿¡ intÇüÀ¸·Î ¼±¾ğÇÏ¿´À½
	char samename[100];
	// samenameÀÌ¶ó´Â ¹®ÀÚ ¹è¿­À» ¸¸µé¾ú´Âµ¥ Å©±â¸¦ 100byte·Î ÇÑ ÀÌÀ¯´Â ¹Ø¿¡¼­ µ¿¸íÀÌÀÎÀ» Ã³¸®ÇÏ´Â °úÁ¤¿¡¼­ samenameÀÌ »ç¿ëµÇ´Âµ¥
	// ³»°¡ ÀÔ·ÂÀ» ¹ŞÀ» ¶§ ¾ó¸¶³ª ÀÔ·ÂÀ» ÇÒÁö ¸ğ¸£±â ¶§¹®¿¡ 100byte·Î ÁöÁ¤ÇÏ¿´À½
	int duplicate = 0;
	// while¹® ¾È¿¡¼­ »ç¿ëÇÒ µ¿¸íÀÌÀÎÀ» Ã³¸®ÇÏ´Â °úÁ¤¿¡¼­ µ¿¸íÀÌÀÎÀÌ ¹ß°ßµÇ¸é 1·Î ¹Ù²î°Ô ÇØ³õ±â À§ÇØ¼­ º¯¼ö¸¦ ÁöÁ¤ÇÔ
	while (repetition) { // repetitionÀº ÇöÀç 1ÀÌ±â ¶§¹®¿¡ ¹«ÇÑ·çÇÁ¸¦ µ¹¾Æ°¨
		printf("ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", telephone[n].name);
		repetition = 0; // ÀÌ¸§À» ÀÔ·Â ¹ŞÀº ÈÄ¿¡´Â ¹İº¹À» ÇÏ°Ô ÇÏ´Â º¯¼öÀÎ  repetitionÀ» 0À¸·Î ¸¸µé¾î¼­ ·çÇÁ¸¦ ³¡³½´Ù.
		duplicate = 0; // »õ·Î¿î ÀÌ¸§À» ÀÔ·Â¹ŞÀ» ¶§¸¶´Ù µ¿¸íÀÌÀÎÀ» È®ÀÎÇÏ´Â °ÍÀ» 0À¸·Î ¹Ù²ã¾ß »õ·Î¿î ¿¬¶ôÃ³·Î µé¾î°¥ ¼ö ÀÖÀ½
		// scanf¸¦ telephone[n].nameÀ¸·Î ¹ŞÀº ÀÌÀ¯´Â ¿¬¶ôÃ³ÀÇ °³¼ö°¡ nÀÌ±â ¶§¹®¿¡ ¸¸¾à ÇöÀç ¿¬¶ôÃ³°¡ 5°³ ÀÖ´Ù¸é
		// 5¹øÂ° ÀÎµ¦½ºÀÇ ÀÌ¸§¿¡ ÀÔ·ÂÀ» ¹Ş°Ô ÇÏ¿´À½
		for (i = 0; i < n; i++) {
			if (strcmp(telephone[n].name, telephone[i].name) == 0) {
				// for¹®À» i=0ºÎÅÍ n±îÁö µ¹¸®¸é¼­ ³»°¡ Áö±İ ÀÔ·ÂÇÑ ÀÌ¸§°ú 0¹øÂ° ÀÎµ¦½º ºÎÅÍ n¹øÂ° ÀÎµ¦½º ±îÁöÀÇ ÀÌ¸§Áß¿¡
				// ³»°¡ ¾Æ±î ÀÔ·ÂÇÑ ÀÌ¸§°ú °°Àº°ÍÀÌ ÀÖ´ÂÁö strcmpÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ Ã£´Â °úÁ¤À» Ç¥ÇöÇÔ
				duplicate = 1; // ¸¸¾à Ã£¾Ò´Ù¸é À§¿¡¼­ ¼³Á¤ÇØ³õÀº duplicate¸¦ 1·Î ÁöÁ¤ÇÔ.
			}
		}
		if (duplicate) {
			// À§¿¡¼­ ¸¸¾à µ¿¸íÀÌÀÎÀ» Ã£¾Æ¼­ duplicate°¡ 1ÀÌ µÈ´Ù¸é ÀÌ if¹®Àº ÂüÀÌ¹Ç·Î ÁøÇàÀÌ µÈ´Ù.
			printf("°°Àº ÀÌ¸§ÀÇ ¿¬¶ôÃ³°¡ ÀÌ¹Ì ÀÖ½À´Ï´Ù.\n");
			printf("°°Àº ÀÌ¸§À» °¡Áø ´Ù¸¥ »ç¶÷ÀÎ°¡¿ä?(´Ù¸¥»ç¶÷ÀÌ¸é 1, °°Àº»ç¶÷ÀÌ¸é 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¹®ÀÚ¿­) ");
			scanf("%s", samename);
			getchar();
			// °°Àº ÀÌ¸§ÀÇ ¿¬¶ôÃ³°¡ ÀÌ¹Ì ÀÖ´Ù°í Ãâ·ÂÀ» ÇÏ°Ô ÇÑÈÄ °°Àº ÀÌ¸§À» °¡Áø ´Ù¸¥ »ç¶÷ÀÌ¸é 1 ¾Æ´Ï¸é ´Ù¸¥ ¹®ÀÚ¿­À» ÀÔ·Â¹ŞÀº ÈÄ¿¡
			// getchar();·Î ³²Àº ¹öÆÛ¸¦ Áö¿ò
			if (samename[0] == '1') {
				printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷À¸·Î Ãß°¡ÇÏ°Ú½À´Ï´Ù.\n");
				// À§¿¡¼­ ¼³Á¤ÇÑ samenameÀÇ ¹è¿­Áß¿¡ 0¹øÂ° Áï Á¦ÀÏ ¾Õ¿¡ ÀÖ´Â ¹®ÀÚ°¡ '1'°ú °°´Ù¸é °°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷À¸·Î Ãß°¡¸¦ ÇÏ°Ô ÇÔ
			}
			else {
				printf("¿¬¶ôÃ³ Ãß°¡¸¦ ÇÏÁö¾Ê¾Ò½À´Ï´Ù.\n\n");
				strcpy(telephone[n].age, "0");
				strcpy(telephone[n].number, "0");
				strcpy(telephone[n].gender, "0");
				strcpy(telephone[n].name, "ÆRÆRÆRÆRÆR"); // ³» ±¸Á¶Ã¼ ¹è¿­¿¡¼­ °¡Àå Å©°Ô ÇÒ ¼ö ÀÖ´Â ÀÌ¸§
				return;
				//¿©±â¿¡¼­ strcpyÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ ÀÌ¸§¿¡ ÆRÆRÆRÆRÆR, ³ªÀÌ¿¡ 0, ÀüÈ­¹øÈ£¿¡ 0, ¼ºº°¿¡ 0À» ³ÖÀº ÀÌÀ¯´Â
				// Áö±İ ÀÌÁ¦ Ãâ·ÂÀÌµÇ´Âµ¥ ¿À¸§Â÷¼ø Á¤·ÄÀÌ µÇ°íÀÖ°í Ãß°¡ÇÔ¼öÀÇ ¸¶Áö¸· ºÎºĞ¿¡¼­ n++À» ÇØÁÖ±â ¶§¹®¿¡ 
				// nÀº ´Ã¾î³ªÁö ¾ÊÀº »óÅÂ¿¡¼­ returnÀ¸·Î ÇÔ¼ö°¡ ³¡³µÀ¸¹Ç·Î ¿À¸§Â÷¼ø ±âÁØ ¸¶Áö¸· ±ÛÀÚÀÎ ÆRÀ» 
				// ³» ±¸Á¶Ã¼ ¹è¿­¿¡¼­ Å©±â¸¦ °¡Àå Å©°Ô ÇÒ ¼ö ÀÖ´Â ÀÌ¸§À¸·Î º¹»ç¸¦ ÇØ¼­ ¸¶Áö¸·¿¡ ³Ö¾î³õ°í ¾²·¹±â °ªÀ» ¾ø¾Ö±â À§ÇØ¼­
				// '1'ÀÌ¿ÜÀÇ ´Ù¸¥ ¹®ÀÚ°¡ µé¾î¿Â´Ù¸é ¿¬¶ôÃ³ Ãß°¡¸¦ ÇÏÁö ¾Ê¾Ò´Ù°í Ãâ·ÂÀ» ÇÑÈÄ ÇÔ¼ö¸¦ Á¾·áÇÑ´Ù.
			}
	}

		if (strlen(telephone[n].name) > 8) {
			printf("ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin);
			// ¸Ç À§¿¡¼­ Àü¿ªº¯¼ö·Î ±¸Á¶Ã¼ ¹è¿­À» ¸¸µé¸é¼­ ÀÌ¸§ÀÇ Å©±â¸¦ 12·Î ÁöÁ¤À» Çß´Âµ¥ ³»°¡ ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ 12byteº¸´Ù Å©´Ù¸é
			// ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä. ¸¦ Ãâ·ÂÇÏ°Ô ÇÑÈÄ repetitonÀ» ´Ù½Ã 1·Î ¸¸µé¾î¼­ ¹«ÇÑ·çÇÁ¸¦ ¸¸µé¾îÁØ´Ù.
			// fflush(stdin);À» ÀÌ¿ëÇØ¼­ ÀÔ·Â ¹öÆÛ¸¦ Áö¿î´Ù.
		}
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");

	repetition = 1; // repetition = 1 ·Î ¸¸µé¾î¼­ while¹®À» Ç×»ó ÂüÀ¸·Î µ¹¾Æ°¡°Ô ÇÑ´Ù
	while (repetition) {
		printf("³ªÀÌ¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", telephone[n].age);
		repetition = 0; 
		// ¿©±â¼­ ´Ù½Ã 0À¸·Î ¹Ù²ÛÈÄ¿¡ ¸¸¾à ³»°¡ ÀÔ·ÂÇÑ ³ªÀÌ°¡ ³Ê¹« ±æ´Ù¸é ´Ù½Ã while¹®À» ¹İº¹ÇØ¾ß ÇÏ±â ¶§¹®¿¡ if¹® ¾È¿¡¼­ ´Ù½Ã 1·Î º¯°æ
		if (strlen(telephone[n].age) > 3) {
			printf("ÀÔ·ÂÇÑ ³ªÀÌ°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin); // ÀÔ·Â ¹öÆÛ¸¦ Áö¿ò
		}
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");
	// À§¿Í °°Àº ±âÁØÀ¸·Î ÀÛ¼ºÇÑ ÄÚµå
	repetition = 1;
	while (repetition) {
		printf("ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä(ex:010-8888-8888): ");
		scanf("%s", telephone[n].number);
		repetition = 0;
		for (i = 0; i < n; i++) {
			if (strcmp(telephone[n].number, telephone[i].number) == 0) {
				printf("ÀüÈ­¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
				repetition = 1;
				break;
				// ÀüÈ­¹øÈ£´Â Àı´ë °°À» ¼ö°¡ ¾ø±â ¶§¹®¿¡ strcmpÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ 0ºÎÅÍ n±îÁöÀÇ ¿¬¶ôÃ³ Áß¿¡¼­ ³»°¡ ÀÔ·ÂÇÑ ÀüÈ­¹øÈ£¿Í
				// °°Àº °ÍÀÌ ÀÖ´Ù¸é ´Ù½Ã 1·Î ¹Ù²ã¼­ while¹®À» Ç×»ó ÂüÀ¸·Î ¸¸µç´Ù.
			}
		}
		if (strlen(telephone[n].number) > 13) {
			printf("ÀÔ·ÂÇÑ ÀüÈ­¹øÈ£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin); 
		} // ¸¸¾à ÀüÈ­¹øÈ£°¡ ³Ê¹« ±æ´Ù¸é ´Ù½Ã ÀÔ·ÂÀ» ¹Ş°Ô ÇÔ
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");
	
	// À§¿Í ¶È°°Àº °³³äÀ¸·Î ÀÛ¼ºµÈ ÄÚµå
	repetition = 1;
	while (repetition) {
		printf("¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä(³²/¿©): ");
		scanf("%s", telephone[n].gender);
		repetition = 0;
		if (strlen(telephone[n].gender) > 3) {
			printf("ÀÔ·ÂÇÑ ¼ºº°ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("Á¦´ë·Î ÀÔ·ÂµÇ¾ú½À´Ï´Ù.\n\n");
	n++; // ÀÌ¸§, ³ªÀÌ, ÀüÈ­¹øÈ£, ¼ºº°À» ´Ù ÀÔ·Â¹ŞÀºÈÄ ¿¬¶ôÃ³ÀÇ °³¼ö¸¦ ´Ã¸² ±×·¡¼­ À§¿¡¼­ ÆR ÀÛ¾÷À» ÇÑ°Í.
	printf("ÀüÈ­¹øÈ£ »ı¼º ¿Ï·á\n\n");
	save(); 
	// ÀÌ¸§, ³ªÀÌ, ÀüÈ­¹øÈ£, ¼ºº°À» ÀÔ·Â¹Ş°í ¿¬¶ôÃ³ °³¼ö¸¦ ´Ã¸°µÚ¿¡ ÀüÈ­¹øÈ£ »ı¼º ¿Ï·á ¶ó´Â ¹®±¸¿Í ÇÔ²² ±× ÀüÈ­¹øÈ£ºÎ¸¦ ÁöÁ¤ÇÑ ÆÄÀÏ¿¡ ÀúÀåÇÏ´Â
	// saveÇÔ¼ö¸¦ È£ÃâÇÏ¿© ÆÄÀÏ¿¡ ÀúÀåÇÒ ¼ö ÀÖ°Ô ÇÑ´Ù
}

void edit() {
	int repetition = 1;
	int duplicate = 0;
	char samename[100]; 
	// samenameÀÌ¶ó´Â ¹è¿­Àº µ¿¸íÀÌÀÎÀ» È®ÀÎÇÒ ¶§ »ç¿ëÇÒ ¹è¿­ÀÎµ¥ ¹è¿­ÀÇ Å©±â¸¦ 100À¸·Î ÇØ³õÀº ÀÌÀ¯´Â 
	// ³»°¡ ÀÔ·ÂÀ» ÇÒ ¶§ ¾ó¸¶³ª ÀÔ·ÂÀ» ÇÒÁö ¸ğ¸£±â ¶§¹®¿¡ 100À¸·Î ÁöÁ¤ÇÔ
	int index;
	while (1) {
		print(); 
		// printÇÔ¼ö¸¦ ¸ÕÀú È£ÃâÇÏ´Â ÀÌÀ¯´Â ¹Ù·Î ¹Ø¿¡¼­ ¼öÁ¤ÇÒ ÀüÈ­¹øÈ£ºÎÀÇ ÀÎµ¦½º ¹øÈ£¸¦ ÀÔ·Â¹ŞÀ»°Çµ¥
		// ¿¬¶ôÃ³ÀÇ ¸ğµç ÀÎµ¦½º¸¦ ¾Ë°íÀÖ´Â °ÍÀÌ ¾Æ´Ï±â ¶§¹®
		printf("¼öÁ¤ÇÒ ÀüÈ­¹øÈ£ºÎÀÇ ÀÎµ¦½º ¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä(¼ıÀÚ¸¸ ÀÔ·Â°¡´É): ");
		scanf("%d", &index);
		// ¹®ÀÚ¿­µµ ÀÔ·Â¹ŞÀ» ¼ö ÀÖ°Ô ÇÏ·Á°í ÇßÀ¸³ª ¿À·ù ¼öÁ¤ ºÒ°¡.
		getchar();
		if (index < 0) {
			printf("´Ù½ÃÀÔ·ÂÇÏ¼¼¿ä.\n");
		}
		else if (index > n) {
			printf("´Ù½ÃÀÔ·ÂÇÏ¼¼¿ä.\n");
		}
		else if (n == 0) {
			printf("ÀüÈ­¹øÈ£ºÎ°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			break;
		}
		else {
			break;
		}
	}
	printf("ÀÎµ¦½º ¹øÈ£: %d\n", index);
	printf("ÀÌ¸§: %s\n", telephone[index].name);
	printf("³ªÀÌ: %s\n", telephone[index].age);
	printf("ÀüÈ­¹øÈ£: %s\n", telephone[index].number);
	printf("¼ºº°: %s\n\n", telephone[index].gender); //¼öÁ¤ÇÒ ÀüÈ­¹øÈ£ºÎ Ãâ·Â
	while (n != 0)
	{
		char select[100]; // selectµµ À§¿Í ¸¶Âù°¡Áö·Î ³»°¡ ¹øÈ£¸¦ ÀÔ·ÂÇÏ´Â °ÍÀÌ ¹®ÀÚ³ª ¹®ÀÚ¿­·Î ¾ó¸¶³ª ¹ŞÀ» Áö ¸ğ¸£±â¿¡ 100À¸·Î ÁöÁ¤
		printf("1. ÀÌ¸§ ¼öÁ¤\n");
		printf("2. ³ªÀÌ ¼öÁ¤\n");
		printf("3. ÀüÈ­¹øÈ£ ¼öÁ¤\n");
		printf("4. ¼ºº° ¼öÁ¤\n");
		printf("5. ÀüÃ¼ ¼öÁ¤\n");
		printf("6. Á¾·á\n");
		printf("¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf("%s", select);
		getchar();

		switch (select[0]) { // select[0]À¸·Î ÇÑ ÀÌÀ¯´Â ¸¸¾à ³»°¡ ÀÔ·ÂÀ» 287294u4·Î Çß´Ù°í °¡Á¤À» ÇÏÀÚ ±×·¯¸é ¿ÀÁ÷ ¾Õ¿¡ ÀÖ´Â 2¸¸ ¹Ş±â À§ÇØ¼­
		case '1':
			repetition = 1;
			while (repetition) {
				char backup[100];
				strcpy(backup, telephone[index].name);
				printf("¼öÁ¤ÇÒ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", telephone[index].name);
				getchar();
				repetition = 0;
				duplicate = 0;
				for (int i = 0; i < n; i++) {
					if (i != index && strcmp(telephone[index].name, telephone[i].name) == 0) {
						duplicate = 1;
					}
				}
				if (duplicate) {
					printf("°°Àº ÀÌ¸§ÀÇ ¿¬¶ôÃ³°¡ ÀÌ¹Ì ÀÖ½À´Ï´Ù.\n");
					printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ ¿¬¶ôÃ³·Î ¼öÁ¤ÇÏ½Ã°Ú½À´Ï±î?(´Ù¸¥»ç¶÷ÀÌ¸é 1 °°Àº»ç¶÷ÀÌ¸é 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¹®ÀÚ¿­) ");
					scanf("%s", samename);
					getchar();
					if (samename[0] == '1') {
						printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ ¿¬¶ôÃ³·Î ¼öÁ¤ÇÏ°Ú½À´Ï´Ù.\n");
					}
					else {
						printf("¿¬¶ôÃ³ ¼öÁ¤À» ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
						strcpy(telephone[index].name, backup);
						return;
					}
				}
				if (strlen(telephone[index].name) > 8) {
					printf("ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					repetition = 1;
					fflush(stdin);
				}
			}
			// ¿¬¶ôÃ³ Ãß°¡¿¡¼­ Çß´ø °³³äÀ» ¶È°°ÀÌ »ç¿ëÇÏ¿© ¼öÁ¤À» ÇÑ°Í
			printf("¼öÁ¤¿Ï·á\n\n");
			printf("ÀÎµ¦½º ¹øÈ£: %d\n", index);
			printf("ÀÌ¸§: %s\n", telephone[index].name);
			printf("³ªÀÌ: %s\n", telephone[index].age);
			printf("ÀüÈ­¹øÈ£: %s\n", telephone[index].number);
			printf("¼ºº°: %s\n\n", telephone[index].gender);
			break;
		case '2':
			repetition = 1;
			while (repetition) {
				printf("¼öÁ¤ÇÒ ³ªÀÌ¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", telephone[index].age);
				repetition = 0;
				if (strlen(telephone[index].age) > 3) {
					printf("ÀÔ·ÂÇÑ ³ªÀÌ°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					repetition = 1;
					fflush(stdin);
				}
			}
			// ÀÌ°Íµµ ¸¶Âù°¡Áö·Î À§¿¡¼­ ³ªÀÌ Ãß°¡ÇÒ ¶§ »ç¿ëÇÑ °³³ä ±×´ë·Î »ç¿ë
			printf("¼öÁ¤¿Ï·á\n\n");
			printf("ÀÎµ¦½º ¹øÈ£: %d\n", index);
			printf("ÀÌ¸§: %s\n", telephone[index].name);
			printf("³ªÀÌ: %s\n", telephone[index].age);
			printf("ÀüÈ­¹øÈ£: %s\n", telephone[index].number);
			printf("¼ºº°: %s\n\n", telephone[index].gender);
			break;
		case '3':
			repetition = 1;
			while (repetition) {
				printf("¼öÁ¤ÇÒ ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä(ex:010-8888-8888): ");
				scanf("%s", telephone[index].number);
				repetition = 0;
				for (int i = 0; i < n; i++) {
					if (i != index && strcmp(telephone[index].number, telephone[i].number) == 0) {
						printf("ÀüÈ­¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
						repetition = 1;
						break;
					}
				}
				if (strlen(telephone[index].number) > 14) {
					printf("ÀÔ·ÂÇÑ ÀüÈ­¹øÈ£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					repetition = 1;
					fflush(stdin);
				}
			}
			// ÀüÈ­¹øÈ£µµ ¸¶Âù°¡Áö À§ÀÇ °³³ä ±×´ë·Î
			printf("¼öÁ¤¿Ï·á\n\n");
			printf("ÀÎµ¦½º ¹øÈ£: %d\n", index);
			printf("ÀÌ¸§: %s\n", telephone[index].name);
			printf("³ªÀÌ: %s\n", telephone[index].age);
			printf("ÀüÈ­¹øÈ£: %s\n", telephone[index].number);
			printf("¼ºº°: %s\n\n", telephone[index].gender);
			break;
		case '4':
			repetition = 1;
			while (repetition) {
				printf("¼öÁ¤ÇÒ ¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", telephone[index].gender);
				repetition = 0;
				if (strlen(telephone[index].gender) > 3) {
					printf("ÀÔ·ÂÇÑ ¼ºº°ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
					repetition = 1;
					fflush(stdin);
				}
			}
			// ¼ºº°µµ À§ÀÇ °³³äÀ» ±×´ë·Î »ç¿ëÇÏ¿´½À´Ï´Ù.
			printf("¼öÁ¤¿Ï·á\n\n");
			printf("ÀÎµ¦½º ¹øÈ£: %d\n", index);
			printf("ÀÌ¸§: %s\n", telephone[index].name);
			printf("³ªÀÌ: %s\n", telephone[index].age);
			printf("ÀüÈ­¹øÈ£: %s\n", telephone[index].number);
			printf("¼ºº°: %s\n\n", telephone[index].gender);
			break;
		case '5':
			repetition = 1;
			while (repetition) {
				char backup[100]; 
				// ¿©±â¿¡¼­ backupÀÌ¶ó´Â ¹è¿­À» 100byte¸¸Å­ÀÇ Å©±â·Î ¸¸µç ÀÌÀ¯´Â ¹Ø¿¡ »ç¿ëÇßÀ» ¶§ ´Ù½Ã ¼³¸íÇÏ°ÚÀ½.
				strcpy(backup, telephone[index].name); // ÀÏ´Ü À§¿¡¼­ backupÀÌ¶ó°í ¸¸µç ¹è¿­¿¡ ÀÔ·Â¹ŞÀº ÀÎµ¦½ºÀÇ ÀÌ¸§À» º¹»çÇØ¼­ ³Ö¾îµÒ
				printf("¼öÁ¤ÇÒ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
				scanf("%s", telephone[index].name);
				getchar();
				repetition = 0;
				duplicate = 0;
				if (strlen(telephone[index].name) > 8) {
					printf("ÀÔ·ÂÇÑ ÀÌ¸§ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n"); // ÀÌ¸§ ±æÀÌ ÃÖ´ëÄ¡ Ã³¸®°úÁ¤
					repetition = 1;
					continue;
					fflush(stdin);
				}
				for (int i = 0; i < n; i++) {
					if (i != index && strcmp(telephone[index].name, telephone[i].name) == 0) {
						duplicate = 1; // µ¿¸íÀÌÀÎ Ã³¸®°úÁ¤
					}
				}
				if (duplicate) {
					printf("°°Àº ÀÌ¸§ÀÇ ¿¬¶ôÃ³°¡ ÀÌ¹Ì ÀÖ½À´Ï´Ù.\n");
					printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ ¿¬¶ôÃ³·Î ¼öÁ¤ÇÏ½Ã°Ú½À´Ï±î?(´Ù¸¥»ç¶÷ÀÌ¸é 1 °°Àº»ç¶÷ÀÌ¸é 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¹®ÀÚ¿­) ");
					scanf("%s", samename); 
					getchar();
					if (samename[0] == '1') {
						printf("°°Àº ÀÌ¸§ÀÇ ´Ù¸¥ ¿¬¶ôÃ³·Î ¼öÁ¤ÇÏ°Ú½À´Ï´Ù.\n");
						repetition = 1;
						while (repetition) { // µ¿¸íÀÌÀÎÀ» Ã³¸®ÇÏ°í ³­ ÈÄ¿¡ ¸¸¾à °°Àº ÀÌ¸§ÀÇ ´Ù¸¥ »ç¶÷ÀÏ ¶§ ³ªÀÌ, ÀüÈ­¹øÈ£, ¼ºº° ¼öÁ¤ÄÚµå
							// ÀÌ ¹Ø¿¡ ³ª¿ÍÀÖ´Â ÄÚµåµéÀº ³ªÀÌ¼öÁ¤, ÀüÈ­¹øÈ£ ¼öÁ¤, ¼ºº° ¼öÁ¤ °úÁ¤¿¡¼­ »ç¿ëÇÑ ÄÚµåµéÀÇ È°¿ëÀÓ
							printf("¼öÁ¤ÇÒ ³ªÀÌ¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
							scanf("%s", telephone[index].age);
							repetition = 0;
							if (strlen(telephone[index].age) > 3) {
								printf("ÀÔ·ÂÇÑ ³ªÀÌ°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
								fflush(stdin);
								repetition = 1;
							}
							else {
								break;
							}
						}
						repetition = 1;
						while (repetition) {
							printf("¼öÁ¤ÇÒ ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä(ex:010-8888-8888): ");
							scanf("%s", telephone[index].number);
							repetition = 0;
							for (int i = 0; i < n; i++) {
								if (i != index && strcmp(telephone[index].number, telephone[i].number) == 0) {
									printf("ÀüÈ­¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
									repetition = 1;
									break;
								}
							}
							if (strlen(telephone[index].number) > 14) {
								printf("ÀÔ·ÂÇÑ ÀüÈ­¹øÈ£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
								repetition = 1;
								fflush(stdin);
							}
						}
						printf("¼öÁ¤ÇÒ ¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä: ");
						scanf("%s", telephone[index].gender);
						if (strlen(telephone[index].gender) > 3) {
							printf("ÀÔ·ÂÇÑ ¼ºº°ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
							repetition = 1;
							continue;
							fflush(stdin);
						}
						printf("¼öÁ¤¿Ï·á\n\n"); // ¼öÁ¤ÀÌ µÇ¾ú´Ù´Â °É º¸¿©ÁÖ±â À§ÇØ ÇØ´ç ÀÎµ¦½ºÀÇ ÀüÈ­¹øÈ£ºÎ¸¦ ÀçÃâ·Â
						printf("ÀÎµ¦½º ¹øÈ£: %d\n", index);
						printf("ÀÌ¸§: %s\n", telephone[index].name);
						printf("³ªÀÌ: %s\n", telephone[index].age);
						printf("ÀüÈ­¹øÈ£: %s\n", telephone[index].number);
						printf("¼ºº°: %s\n\n", telephone[index].gender);
					}
					// ¸¸¾à °°ÀºÀÌ¸§ÀÇ µ¿¸íÀÌÀÎÀ» ¼öÁ¤ÇÏ´Â °úÁ¤¿¡¼­ÀÇ if¹®ÀÌ ³¡³ª´Â °÷

					else {
						printf("¿¬¶ôÃ³ ¼öÁ¤À» ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
						strcpy(telephone[index].name, backup);
						return;
						// ¿©±â¿¡¼­ ¸¸¾à¿¡ ÀÌ¸§¿¡ µ¿¸íÀÌÀÎÀÌ ÀÖ¾î¼­ µ¿¸íÀÌÀÎ¿¡¼­ Ã³¸®¸¦ ÇØ¹ö·È´Âµ¥ ¿¬¶ôÃ³ ¼öÁ¤À» ÇÏÁö ¾Ê¾Ò´Ù°í ³¡³ª¹ö¸®¸é
						// ÀÌ¸§Àº ¹Ù²î°í ³ª¸ÓÁö´Â ¾È¹Ù²î±â ¶§¹®¿¡ backupÀ¸·Î ¿Ã·Á³õÀº °ªÀ» ´Ù½Ã ÀÔ·ÂÇÑ ÀÎµ¦½ºÀÇ ÀÌ¸§À¸·Î ³ÖÀº°Í.
					}
				}
				else { // µ¿¸íÀÌÀÎÀÌ ¾Æ´Ò ¶§ ³ªÀÌ, ÀüÈ­¹øÈ£, ¼ºº°À» ¼öÁ¤ÇÏ´Â ÄÚµå À§ÀÇ °Í È°¿ëÇÑ°Í
					repetition = 1;
					while (repetition) {
						printf("¼öÁ¤ÇÒ ³ªÀÌ¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
						scanf("%s", telephone[index].age);
						repetition = 0;
						if (strlen(telephone[index].age) > 3) {
							printf("ÀÔ·ÂÇÑ ³ªÀÌ°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
							fflush(stdin);
							repetition = 1;
						}
						else {
							break;
						}
					}
					repetition = 1;
					while (repetition) {
						printf("¼öÁ¤ÇÒ ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä(ex:010-8888-8888): ");
						scanf("%s", telephone[index].number);
						repetition = 0;
						for (int i = 0; i < n; i++) {
							if (i != index && strcmp(telephone[index].number, telephone[i].number) == 0) {
								printf("ÀüÈ­¹øÈ£´Â °°À» ¼ö ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
								repetition = 1;
								break;
							}
						}
						if (strlen(telephone[index].number) > 14) {
							printf("ÀÔ·ÂÇÑ ÀüÈ­¹øÈ£°¡ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
							repetition = 1;
							fflush(stdin);
						}
					}
					repetition = 1;
					while (repetition) {
						printf("¼öÁ¤ÇÒ ¼ºº°À» ÀÔ·ÂÇÏ¼¼¿ä: ");
						scanf("%s", telephone[index].gender);
						repetition = 0;
						if (strlen(telephone[index].gender) > 3) {
							printf("ÀÔ·ÂÇÑ ¼ºº°ÀÌ ³Ê¹« ±é´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
							repetition = 1;
							fflush(stdin);
						}
					}

					printf("¼öÁ¤¿Ï·á\n\n"); // ¼öÁ¤ÀÌ µÇ¾ú´Ù´Â °É º¸¿©ÁÖ±â À§ÇØ ÇØ´ç ÀÎµ¦½ºÀÇ ÀüÈ­¹øÈ£ºÎ¸¦ ÀçÃâ·Â
					printf("ÀÎµ¦½º ¹øÈ£: %d\n", index);
					printf("ÀÌ¸§: %s\n", telephone[index].name);
					printf("³ªÀÌ: %s\n", telephone[index].age);
					printf("ÀüÈ­¹øÈ£: %s\n", telephone[index].number);
					printf("¼ºº°: %s\n\n", telephone[index].gender);
					return;
				}
			}
			break;
		case '6':
			printf("¾Æ¹«°Íµµ ¼öÁ¤ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
			break;
		default:
			printf("´Ù½ÃÀÔ·ÂÇÏ¼¼¿ä.\n\n");
			continue;
		}
		break;
	}
}

void deletenumber() {
	int index;
	char select[100]; // select¶ó´Â º¯¼ö·Î ¹®ÀÚ¿­ ¹è¿­À» 100byte¸¸Å­ÀÇ Å©±â·Î ¹Ş¾Æ¼­ ³»°¡ ¹øÈ£¸¦ ÀÔ·ÂÇÒ ¶§ ¼ıÀÚ¸¸ÀÌ ¾Æ´Ñ ¹®ÀÚ·Îµµ ÀÔ·ÂÀ» °¡´ÉÇÏ°Ô ÇÔ
	char really[100]; // À§¿Í °°Àº ÀÌÀ¯
	while (1) {
		printf("1. ÀüÃ¼»èÁ¦ \n");
		printf("2. ºÎºĞ»èÁ¦ \n");
		printf("¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		scanf(" %s", select);
		getchar();
		index = select[0] - (int)'0'; 
		// ÀÌ ÄÚµå´Â Áö±İ À§¿¡¼­ index°¡ Á¤¼öÇüÀ¸·Î ¹Ş¾Ò±â ¶§¹®¿¡ index¿¡´Â Á¤¼ö¸¸ µé¾î°¥ ¼ö ÀÖ´Ù
		// ÇÏÁö¸¸ select´Â ¹®ÀÚ±â ¶§¹®¿¡ select¿¡ ¿¹¸¦ µé¾î 2982dkshdka2°¡ ÀÔ·ÂÀÌ µÇ¾ú´Ù°í ÇØµµ
		// select¹è¿­¿¡¼­ 0¹øÂ° ÀÎµ¦½º¸¸ °¡Á®¿Á ¶§¹®¿¡ ¹®ÀÚ '2'¸¸ ¹Ş°Ô µÈ´Ù.
		// ¿©±â¿¡¼­ Á¤¼öÇü 0ÀÇ ¹®ÀÚ Áï, ¾Æ½ºÅ° ÄÚµå °ªÀ» »©¼­ ¹®ÀÚ¿­ '2'ÀÇ ¾Æ½ºÅ° ÄÚµå°ª°ú '0'ÀÇ ÄÚµå°ªÀ» »©¼­ ¼ıÀÚ 2·Î ¸¸µå´Â °úÁ¤ÀÓ
		if (n == 0) {
			printf("ÀüÈ­¹øÈ£ºÎ¿¡ ¿¬¶ôÃ³°¡ ¾ø½À´Ï´Ù.\n\n");
			return;
		}
		switch (select[0]) {
		case '1':
			printf("Á¤¸» »èÁ¦ÇÏ½Ã°Ú½À´Ï±î?(1À» ´©¸£¸é »èÁ¦ 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¼ıÀÚ, ¹®ÀÚ ÀÔ·Â½Ã »èÁ¦¾ÈÇÔ) ");
			scanf(" %s", really);
			if (really[0] == '1') {
				n = 0;
				printf("¿¬¶ôÃ³°¡ ÀüÃ¼»èÁ¦µÇ¾ú½À´Ï´Ù.\n\n");
				return;
				// 1À» ÀÔ·ÂÇÏ¸é ÀüÃ¼»èÁ¦°¡ µÇ°í ±× ¿ÜÀÇ ¹®ÀÚ¸¦ ÀÔ·ÂÇÏ¸é ¸Ş´º·Î ³Ñ¾î°¨
			}
			else {
				printf("ÀüÃ¼»èÁ¦¸¦ ÇÏÁö ¾Ê¾Ò½À´Ï´Ù.\n\n");
				return;
			}
		case '2':
			print(); // ÀÌ°Íµµ ¼öÁ¤ÇÔ¼ö¿Í ¸¶Âù°¡Áö·Î ¹Ì¸® ¿¬¶ôÃ³¸¦ Ãâ·ÂÇÏ¿© ¸î¹øÂ°ÀÇ ÀÎµ¦½º¸¦ Áö¿ïÁö ¼±ÅÃÇÏ±â À§ÇØ¼­ ¿¬¶ôÃ³¸¦ Ãâ·ÂÇÔ
			printf("»èÁ¦ÇÒ ÀüÈ­¹øÈ£ºÎÀÇ ÀÎµ¦½º ¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
			scanf("%d", &index);
			getchar();
			printf("ÀÌ¸§: %s\n", telephone[index].name);
			printf("³ªÀÌ: %s\n", telephone[index].age);
			printf("ÀüÈ­¹øÈ£: %s\n", telephone[index].number);
			printf("¼ºº°: %s\n\n", telephone[index].gender);
			printf("Á¤¸» »èÁ¦ÇÏ½Ã°Ú½À´Ï±î?(1: »èÁ¦ 1ÀÌ¿ÜÀÇ ´Ù¸¥ ¹®ÀÚ¿­: »èÁ¦ ¾ÈÇÔ): ");
			scanf("%s", really);
			getchar();
			if (really[0] == '1') {
				for (int i = index; i < n; i++) {
					telephone[i] = telephone[i + 1];
				}
				//really ¹è¿­¿¡¼­ Á¦ÀÏ ¾Õ¿¡ ÀÖ´Â°ÍÀÌ ¹®ÀÚ¿­ 1ÀÌ¸é ÇØ´ç ÀÎµ¦½º¸¦ »èÁ¦ÇÏ°í ¹è¿­ÀÌ ºñ±â ¶§¹®¿¡ µÚ¿¡ ÀÖ´Â ¹è¿­À» ¾ÕÀ¸·Î Ã¤¿ò
				printf("»èÁ¦¿Ï·á.\n\n");
				n--;
				return;
			}
			else {
				printf("´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n\n");
				return;
			}
		default:
			printf("´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä.\n");
			break;
		}
	}
}

void search() {
	char nameornumber[100]; // nameornumber¶ó´Â ¹®ÀÚ¿­ ¹è¿­À» 100byte·Î ¸¸µé¾î¼­ À§¿Í °°Àº ¹æ½ÄÀ¸·Î Ã³¸®ÇÏ±â À§ÇÔ
	int searching = 0; // ¸¸¾à ¹®ÀÚ¿­À» °Ë»öÇßÀ» ¶§ °á°ú°¡ ÀÖÀ¸¸é 1ÀÌ µÇ°í ¾Æ´Ï¸é 0ÀÌ ±×´ë·Î °¡´Âµ¥ ¸¸¾à ÀÌ º¯¼ö°¡ 0ÀÌ¸é °Ë»ö °á°ú°¡ ¾ø´Â °Í
	while (1) {
		printf("°Ë»öÇÒ ³»¿ëÀ» ÀÔ·ÂÇÏ¼¼¿ä(ºÎºĞ ¹®ÀÚ °Ë»ö°¡´É): ");
		scanf("%s", nameornumber);
		for (int i = 0; i < size; i++)
		{
			if (strstr(telephone[i].name, nameornumber)) {
				printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);	
				printf("ÀÌ¸§: %s\n", telephone[i].name);
				printf("³ªÀÌ: %s\n", telephone[i].age);
				printf("ÀüÈ­¹øÈ£: %s\n", telephone[i].number);
				printf("¼ºº°: %s\n\n", telephone[i].gender);
				searching = 1;
				// strstrÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ ³»°¡ ÀÔ·ÂÇÑ ¹®ÀÚ¿Í i=0ºÎÅÍ n-1±îÁö ¹İº¹ÇÏ¸é¼­ ¹®ÀÚ¿­ÀÌ ÀÖ´ÂÁö È®ÀÎÇØÁÜ
				// ¸¸¾à ÀÖ´Ù¸é ±× ¹®ÀÚ¸¦ °¡Áö°í ÀÖ´Â ¸ğµç ¿¬¶ôÃ³¸¦ Ãâ·ÂÇÔ
			}
			else if (strstr(telephone[i].age, nameornumber)) {
				printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
				printf("ÀÌ¸§: %s\n", telephone[i].name);
				printf("³ªÀÌ: %s\n", telephone[i].age);
				printf("ÀüÈ­¹øÈ£: %s\n", telephone[i].number);
				printf("¼ºº°: %s\n\n", telephone[i].gender);
				searching = 1;
				// À§¿Í °°Àº °³³ä »ç¿ë
			}
			else if (strstr(telephone[i].number, nameornumber)) {
				printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
				printf("ÀÌ¸§: %s\n", telephone[i].name);
				printf("³ªÀÌ: %s\n", telephone[i].age);
				printf("ÀüÈ­¹øÈ£: %s\n", telephone[i].number);
				printf("¼ºº°: %s\n\n", telephone[i].gender);
				searching = 1;
				// À§¿Í °°Àº °³³ä »ç¿ë
			}
			else if (strstr(telephone[i].gender, nameornumber)) {
				printf("ÀÎµ¦½º ¹øÈ£: %d\n", i);
				printf("ÀÌ¸§: %s\n", telephone[i].name);
				printf("³ªÀÌ: %s\n", telephone[i].age);
				printf("ÀüÈ­¹øÈ£: %s\n", telephone[i].number);
				printf("¼ºº°: %s\n\n", telephone[i].gender);
				searching = 1;
				// À§¿Í °°Àº °³³ä »ç¿ë
			}
		}

		if (searching == 0) {
			printf("°Ë»öÇÑ ÀÌ¸§ ¶Ç´Â ÀüÈ­¹øÈ£°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
			break;
			// À§¿¡¼­ ¸¸µé¾îµĞ searching == 0ÀÌ¸é °Ë»ö°á°ú°¡ ¾ø´Â °ÍÀÓ
		}
		break;
	}
}


int static compare(const void* first, const void* second)
{
	return strcmp(((address*)first) -> name, ((address*)second) -> name); 
	// firstÆ÷ÀÎÅÍ¿¡ ÀÌ¸§, second Æ÷ÀÎÅÍ¿¡µµ ÀÌ¸§ÀÌ µé¾î°£ÈÄ qsortÇÔ¼ö¿¡¼­ ÀÌ¸§À» ±âÁØÀ¸·Î ¿À¸§Â÷¼ø Á¤·ÄÀ» ÇÔ.
}
// first´Â Ã¹¹øÂ° ¿ä¼Ò¸¦ °¡¸®Å³ Æ÷ÀÎÅÍ, second´Â µÎ¹øÂ° ¿ä¼Ò¸¦ °¡¸®Å³ Æ÷ÀÎÅÍ
// voidÀ» »ç¿ëÇÑ ÀÌÀ¯´Â qsort()ÇÔ¼ö¸¦ »ç¿ëÇÏ±â À§ÇØ¼­ qsort´Â ¾î¶² Å¸ÀÔÀÇ µ¥ÀÌÅÍµµ ¹ŞÀ» ¼ö ÀÖ¾î¾ß ÇÔ
// ÀúÀåµÈ ¿¬¶ôÃ³¸¦ ÀÌ¸§ ±âÁØÀ¸·Î ¿À¸§Â÷¼ø Á¤·ÄÀ» ÇÏ±â À§ÇØ¼­ »ç¿ëÇÔ

void print() {
	int i;
	qsort(telephone, size, sizeof(address), compare); // qsort()ÇÔ¼ö¸¦ »ç¿ëÇØ¼­ ÀÌ¸§À» ¿À¸§Â÷¼ø Á¤·ÄÀ» ÇÑ ÈÄ¿¡ Ãâ·ÂÀ» ÇÔ
	if (n > 0) {
		for (i = 0; i < n; i++) {
			printf("ÀÎµ¦½º ¹øÈ£ %d\n", i);
			printf("ÀÌ¸§: %s\n", telephone[i].name);
			printf("³ªÀÌ: %s\n", telephone[i].age);
			printf("ÀüÈ­¹øÈ£: %s\n", telephone[i].number);
			printf("¼ºº°: %s\n\n", telephone[i].gender);
		}
	}
	else {
		printf("ÀüÈ­¹øÈ£ºÎ°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
	}
}

void save() {
	FILE* numberbook;
	numberbook = fopen("C:\\Temp\\Number.txt", "w");
	if (numberbook == NULL) {
		printf("ÆÄÀÏÀ» ¿­Áö ¸øÇß½À´Ï´Ù.");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		fprintf(numberbook, " %s %s %s %s\n",
			telephone[i].name,
			telephone[i].age,
			telephone[i].number,
			telephone[i].gender);
	} //fprintf°¡ ÆÄÀÏ¿¡ Ãâ·ÂÀ» ÇÏ´Â °ÍÀÌ±â ¶§¹®¿¡ ÀüÈ­¹øÈ£ºÎ¿¡ ÀÖ´Â name,age,number,gender¸¦ °¢ ÀÎµ¦½º¿¡ ¸Â°Ô ÆÄÀÏ¾È¿¡ Ãâ·ÂÀ» ÇÏ°í ÀúÀåÀ» ÇÔ.
	fclose(numberbook);
	printf("ÀüÈ­¹øÈ£°¡ ÆÄÀÏ¿¡ ÀúÀåµÇ¾ú½À´Ï´Ù.\n\n");
}
void load() {
	FILE* numberbook;
	numberbook = fopen("C:\\Temp\\Number.txt", "r");
	if (numberbook == NULL) {
		printf("ÆÄÀÏÀ» ¿­Áö ¸øÇß½À´Ï´Ù.");
		exit(1);
	}
	while (!feof(numberbook)) {
		fscanf(numberbook, "%s %s %s %s",
			telephone[n].name,
			telephone[n].age,
			telephone[n].number,
			telephone[n].gender);
		n++;
		if (n >= size) {
			size = size * 2;
			telephone = (address*)realloc(telephone, size * sizeof(address));
		}
	}
	n--;
}