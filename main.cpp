#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <comdef.h>
#include <d3d12.h>
#include "TextureConverter.h"

enum Argument {
	kApplicationPath,	//アプリケーションのパス
	kFilePath,			//渡されたファイルのパス

	NumArgument
};

int main(int argc, char* argv[]) {

	//for (int i = 0; i < argc; i++) {
	//	printf(argv[i]);
	//	//改行
	//	printf("\n");
	//}

	/*assert(argc >= NumArgument);*/

	//コマンドライン引数指定なし
	if (argc < NumArgument)
	{
		//使い方を表示する
		TextureConverter::OutputUsage();
		return 0;
	}

	//ライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//オプションの数
	int numOptions = argc - NumArgument;
	//オプション配列(ダブルポインタ)
	char** options = argv + NumArgument;

	//テクスチャコンバータ
	TextureConverter converter;

	converter.ConverterTextureWICToDDS(argv[kFilePath], numOptions, options);

	//COMライブラリの終了
	CoUninitialize();

	/*system("pause");*/
	return 0;
}