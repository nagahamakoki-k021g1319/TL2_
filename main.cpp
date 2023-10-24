#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <comdef.h>
#include <d3d12.h>
#include "TextureConverter.h"

enum Argument {
	kApplicationPath,	//�A�v���P�[�V�����̃p�X
	kFilePath,			//�n���ꂽ�t�@�C���̃p�X

	NumArgument
};

int main(int argc, char* argv[]) {

	//for (int i = 0; i < argc; i++) {
	//	printf(argv[i]);
	//	//���s
	//	printf("\n");
	//}

	assert(argc >= NumArgument);

	//���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	converter.ConverterTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	system("pause");
	return 0;
}