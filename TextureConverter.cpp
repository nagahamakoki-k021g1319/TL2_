#include "TextureConverter.h"

#include <windows.h>

void TextureConverter::ConverterTextureWICToDDS(const std::string& filePath)
{
	//�e�N�X�`���t�@�C����ǂݍ���
	LoadWICTextureFromFile(filePath);
}



void TextureConverter::SeparateFilePath(const std::wstring& filePath)
{
}

void TextureConverter::SaveDDSTextureToFile()
{
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& String)
{
	//���C�h������ɕϊ������ۂ̕��������v�Z
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, String.c_str(), -1, nullptr, 0);

	//���C�h������
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, String.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}
