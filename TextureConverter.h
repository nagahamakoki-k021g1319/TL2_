#pragma once
#include <string>
#include <DirectXTex.h>

class TextureConverter
{
public:
	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name = "fliePath">�t�@�C���p�X</param>
	void ConverterTextureWICToDDS(const std::string& filePath);

	/// <summary>
	/// �p�X�ƃt�@�C�����𕪗�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void SeparateFilePath(const std::wstring& filePath);

	
	/// <summary>
	/// �e�N�X�`���t�@�C���ǂݍ���
	/// </summary>
	/// <param name = "fliePath">�t�@�C���p�X</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	static std::wstring ConvertMultiByteStringToWideString(const std::string& String);

private:
	/// <summary>
	/// DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	/// </summary>
	void SaveDDSTextureToFile();


private:
	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�̃C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;

	//�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�t�@�C���g���q
	std::wstring fileExt_;
};

