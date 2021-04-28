#include <windows.h>
#include <stdio.h>

const char g_szClassName[] = "myWindowClass";

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}



typedef struct windowDef window;
typedef struct windowDef
{
	int x;
	int y;
	int w;
	int h;
	char * name;
	char * className;
	
	///////////////reserved
	HWND hwnd;
	MSG msg;
	
	
} window;

void _windowInit(window * at)
{
	
	WNDCLASSEX wc;
   // HWND hwnd;
    //MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = GetModuleHandle(0);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = at->className;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return;
    }

    // Step 2: Creating the Window
    at->hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        at->className,
        at->name,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, at->w, at->h,
        NULL, NULL, GetModuleHandle(0), NULL);

    if(at->hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return;
    }
	
    ShowWindow(at->hwnd, SW_SHOWNORMAL);
    UpdateWindow(at->hwnd);
	
}

void windowInit(window * at)
{
	printf("done\r\n");
	at->x = 0;
	at->y =0;
	at->w = 800;
	at->h = 600;
	at->name = "";
	at->className ="windowClass";
	_windowInit(at);
	
	
}

void windowInitFull(window * at, int w, int h, char * name, char * className)
{
	at->x = 0;
	at->y = 0;
	at->w = w;
	at->h = h;
	at->name = name;
	at->className = className;
	_windowInit(at);
}

void windowDestory(window * at)
{
	at->name = "";
	at->className = "";
	
}

void windowMessageLoop(window * at)
{
	while(GetMessage(&(at->msg), NULL, 0, 0) > 0)
    {
        TranslateMessage(&(at->msg));
        DispatchMessage(&(at->msg));
    }
}
/*
int main()
{
	printf("size: %d\r\n", sizeof(HWND));
    

    // Step 3: The Message Loop
	while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
*/