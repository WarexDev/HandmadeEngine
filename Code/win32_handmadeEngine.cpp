#include <windows.h>


LRESULT CALLBACK 
MainWindowCallback(	HWND pWindow,
					UINT iMessage,
					WPARAM pWParam,
					LPARAM pLParam )
{
	LRESULT pLResult = NULL;

	switch ( iMessage )
	{
		case WM_ACTIVATEAPP: 
		{
			OutputDebugStringA("WM_ACTIVATEAPP\n");
		} break;

		case WM_SIZE:
		{
			OutputDebugStringA("WM_SIZE\n");
		} break;

		case WM_CLOSE:
		{
			OutputDebugStringA("WM_CLOSE\n");
		} break;

		case WM_DESTROY:
		{
			OutputDebugStringA("WM_DESTROY\n");
		} break;

		default:
		{
			pLResult =  DefWindowProc( pWindow, iMessage, pWParam, pLParam );
		}break;
	}

	return pLResult;
}

int CALLBACK
WinMain( HINSTANCE	pInstance,
		 HINSTANCE	pPrevInstance,
		 LPSTR		pCommandLine,
		 int		iCmdShow )
{
	WNDCLASS oWindowClass = {};

	// TODO: check if CS_OWNDC|CS_HREDRAW|CS_VREDRAW still matter
	oWindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
	oWindowClass.lpfnWndProc = MainWindowCallback;
	oWindowClass.hInstance = pInstance;
//		oWindowClass.hIcon = ;
	oWindowClass.lpszClassName = "HandmadeEngineWindowClass";

	if ( RegisterClass( &oWindowClass ) )

	{
		HWND pWindowHandler = CreateWindowEx(
			0, // Optional window styles.
			oWindowClass.lpszClassName, // Window class
			"Handmade Engine", // Window text
			WS_OVERLAPPEDWINDOW|WS_VISIBLE, // Window style
			// Size and position
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,       // Parent window    
			NULL,       // Menu
			pInstance,  // Instance handle
			NULL        // Additional application data
			);

		if (pWindowHandler)
		{
			ShowWindow( pWindowHandler, iCmdShow );
		}
		else
		{
			// TODO : Log error
		}
	}
	else
	{
		// TODO : Log error
	}

	return 0;
}

