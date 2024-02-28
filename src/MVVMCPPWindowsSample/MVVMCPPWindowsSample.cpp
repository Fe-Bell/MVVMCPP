// MVVMCPPWindowsSample.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "MVVMCPPWindowsSample.h"
#include "ViewModelLocator.hpp"
#include <string>
#include <iostream>
#include "WeakMessenger.hpp"
#include "BasicMessage.hpp"
#include "fCppStringUtils.hpp"
#include <string.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
HWND mainWindow;
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
AppViewModel::ViewModelLocator locator{};
void onMainViewModelPropertyChanged(const std::string& propertyName);
void onMessageReceived(const Messaging::WeakMessenger::SafeMessagePtr& message);


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MVVMCPPWINDOWSSAMPLE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    locator.getMainViewModel()->subscribePropertyChangedEvent(onMainViewModelPropertyChanged);

    Messaging::WeakMessenger::instance()->subscribeListener(hInstance, onMessageReceived);

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MVVMCPPWINDOWSSAMPLE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


static void getWindowCenter(HWND parent_window, int width, int height, RECT& rect)
{
    ::GetClientRect(parent_window, &rect);
    rect.left = (rect.right / 2) - (width / 2);
    rect.top = (rect.bottom / 2) - (height / 2);
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex{};

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MVVMCPPWINDOWSSAMPLE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MVVMCPPWINDOWSSAMPLE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   RECT rect;
   int width = 800, height = 600;
   getWindowCenter(::GetDesktopWindow(), width, height, rect);
   
   mainWindow = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       rect.left, rect.top, width, height, nullptr, nullptr, hInstance, nullptr);

   if (!mainWindow)
   {
      return FALSE;
   }

   ShowWindow(mainWindow, nCmdShow);
   UpdateWindow(mainWindow);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_FILE_CHANGESTATE:
                locator.getMainViewModel()->setState(!locator.getMainViewModel()->getState());
                break;
            case ID_FILE_TESTMESSAGE:
                locator.getMainViewModel()->getTestCommand()->execute();
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void onMainViewModelPropertyChanged(const std::string& propertyName)
{
    std::wstring widestr = std::wstring(propertyName.begin(), propertyName.end()) + L" changed to " + std::to_wstring(locator.getMainViewModel()->getState());
    MessageBox(mainWindow, widestr.c_str(), L"MVVM CPP Lib", MB_OK);
}

void onMessageReceived(const Messaging::WeakMessenger::SafeMessagePtr& message)
{
    BasicMessage* msg = dynamic_cast<BasicMessage*>(message.get());
    if (msg != nullptr)
    {
        const char* content = msg->getContent();
        if (content != nullptr) {
            //Format message content
            std::wstring wstr = L"Message received: " + std::wstring(content, content + strlen(content));

            MessageBox(mainWindow, wstr.c_str(), L"MVVM CPP Lib", MB_OK);
        }
        else {
            //No message content
            MessageBox(mainWindow, L"Message received!", L"MVVM CPP Lib", MB_OK);
        }

        return;
    }
    
    //The message type was not recognized
    MessageBox(mainWindow, L"A message was received!", L"MVVM CPP Lib", MB_OK);
}