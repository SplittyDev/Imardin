#ifndef __IMARDIN_WINDOW_H
#define __IMARDIN_WINDOW_H

#ifdef WIN32

#include <windows.h>
#include <stdbool.h>

#define APPNAME "ImardinVM"
#define APPTITLE "Imardin Virtual Machine"

char szAppName [] = APPNAME;
char szTitle [] = APPTITLE;
char* pWindowText = NULL;

HINSTANCE g_hInst;

char* messages [1024];
int messagecount = 0;

void PrintMessage (char msg [])
{
	messages[messagecount] = msg;
	if (messagecount == 25) messagecount = 0;
	else messagecount++;
}

void CenterWindow (HWND hwnd_self)
{
	RECT rw_self, rc_parent, rw_parent; HWND hwnd_parent;
	hwnd_parent = GetParent (hwnd_self);
	if (NULL == hwnd_parent) hwnd_parent = GetDesktopWindow ();
	GetWindowRect (hwnd_parent, &rw_parent);
	GetClientRect (hwnd_parent, &rc_parent);
	GetWindowRect (hwnd_self, &rw_self);
	SetWindowPos (hwnd_self, NULL,
		rw_parent.left + (rc_parent.right + rw_self.left - rw_self.right) / 2,
		rw_parent.top  + (rc_parent.bottom + rw_self.top - rw_self.bottom) / 2,
		0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_CREATE:
			CenterWindow (hwnd);
			break;

		case WM_DESTROY:
			PostQuitMessage (0);
			break;


		case WM_RBUTTONUP:
			DestroyWindow (hwnd);
			break;

		case WM_KEYDOWN:
			if (VK_ESCAPE == wParam)
				DestroyWindow (hwnd);
			break;


		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC         hdc;
			RECT        rc;
			hdc = BeginPaint (hwnd, &ps);

			GetClientRect (hwnd, &rc);
			SetTextColor (hdc, RGB(255,255,255));
			SetBkMode (hdc, TRANSPARENT);

			int i = 0;
			for (i; i < 25; i++)
			{
				DrawText (hdc, messages[i], -1, &rc, DT_SINGLELINE);
			}

			EndPaint (hwnd, &ps);
			break;
		}

		default:
			return DefWindowProc (hwnd, message, wParam, lParam);
	}
	return 0;
}

int APIENTRY WinMain(
				HINSTANCE hInstance,
				HINSTANCE hPrevInstance,
				LPSTR     lpCmdLine,
				int       nCmdShow)
{
	MSG msg;

	WNDCLASS wc;

	HWND hwnd;

	ZeroMemory (&wc, sizeof wc);
	wc.hInstance     = hInstance;
	wc.lpszClassName = szAppName;
	wc.lpfnWndProc   = (WNDPROC)WndProc;
	wc.style         = CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW;
	wc.hbrBackground = (HBRUSH)GetStockObject (BLACK_BRUSH);
	wc.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor (NULL, IDC_ARROW);

	if (FALSE == RegisterClass (&wc)) return 0;

	hwnd = CreateWindow(
		szAppName,
		szTitle,
		WS_OVERLAPPEDWINDOW|WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		360,
		240,
		0,
		0,
		g_hInst,
		0);

	if (NULL == hwnd) return 0;

	pWindowText = lpCmdLine[0] ? lpCmdLine : "Loading your Imardin assembly...";

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

#endif

#endif