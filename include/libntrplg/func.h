#ifndef FUNC_H
#define FUNC_H


/* set RWX on remote process's memory */
u32 protectRemoteMemory(Handle hProcess, void* addr, u32 size);
/* set RWX on current process's memoroy */
u32 protectMemory(void* addr, u32 size);



extern Handle fsUserHandle;
extern FS_archive sdmcArchive;



#define MAX_PLUGIN_COUNT 32

/* plugin loader info structure */
typedef struct _PLGLOADER_INFO {
	u32 plgCount;
	u32 plgBufferPtr[MAX_PLUGIN_COUNT];
	u32 plgSize[MAX_PLUGIN_COUNT];
	u32 arm11BinStart;
	u32 arm11BinSize;
/* the titleid of the loaded process (available for game plugins only) */
	u32 tid[2];
} PLGLOADER_INFO;

/* flush the screen framebuffer */
void updateScreen();
/* show the menu */
s32 showMenu(u8* title, u32 entryCount, u8* captions[]);
/* show a message dialog */
int showMsg(u8* msg);
/* xsprintf(buf, fmt, v1, v2); showMsg(buf) */
void showDbg(u8* fmt, u32 v1, u32 v2);
/* copy kernel memory */
void kmemcpy(void* dst, void* src, u32 size) ;



#define CURRENT_PROCESS_HANDLE	0xffff8001

#endif