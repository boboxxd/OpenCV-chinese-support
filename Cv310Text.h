//====================================================================  
//====================================================================  
// �ļ�: Cv310Text.h   
// ˵��: OpenCV310�������    
// ʱ��:  2016-11-11 
// ��д����: zmdsjtu@163.com  
//���͵�ַ:http://blog.csdn.net/zmdsjtu/article/category/6371625

//ԭ���ߣ� chaishushan#gmail.com   2007-8-21
//====================================================================  
//====================================================================  

#ifndef OPENCV_Cv310Text_2016_11_11_ZMD 
#define OPENCV_Cv310Text_2016_11_11_ZMD 


#include <ft2build.h>  
#include FT_FREETYPE_H
#include <opencv2/opencv.hpp>



class Cv310Text
{


	//================================================================  
	//================================================================  

public:

	/**
	* װ���ֿ��ļ�
	*/

	Cv310Text(const char *freeType);
	virtual ~Cv310Text();

	//================================================================  
	//================================================================  

	/**
	* ��ȡ���塣Ŀǰ��Щ�����в�֧�֡�
	*
	* \param font        ��������, Ŀǰ��֧��
	* \param size        �����С/�հױ���/�������/��ת�Ƕ�
	* \param underline   �»���
	* \param diaphaneity ͸����
	*
	* \sa setFont, restoreFont
	*/

	void getFont(int *type,
		CvScalar *size = NULL, bool *underline = NULL, float *diaphaneity = NULL);

	/**
	* �������塣Ŀǰ��Щ�����в�֧�֡�
	*
	* \param font        ��������, Ŀǰ��֧��
	* \param size        �����С/�հױ���/�������/��ת�Ƕ�
	* \param underline   �»���
	* \param diaphaneity ͸����
	*
	* \sa getFont, restoreFont
	*/

	void setFont(int *type,
		CvScalar *size = NULL, bool *underline = NULL, float *diaphaneity = NULL);

	/**
	* �ָ�ԭʼ���������á�
	*
	* \sa getFont, setFont
	*/

	void restoreFont();

	//================================================================  
	//================================================================  

	/**
	* �������(��ɫĬ��Ϊ��ɫ)����������������ַ���ֹͣ��
	*
	* \param img  �����Ӱ��
	* \param text �ı�����
	* \param pos  �ı�λ��
	*
	* \return ���سɹ�������ַ����ȣ�ʧ�ܷ���-1��
	*/

	int putText(cv::Mat &frame, const char    *text, CvPoint pos);

	/**
	* �������(��ɫĬ��Ϊ��ɫ)����������������ַ���ֹͣ��
	*
	* \param img  �����Ӱ��
	* \param text �ı�����
	* \param pos  �ı�λ��
	*
	* \return ���سɹ�������ַ����ȣ�ʧ�ܷ���-1��
	*/

	int putText(cv::Mat &frame, const wchar_t *text, CvPoint pos);

	/**
	* ������֡���������������ַ���ֹͣ��
	*
	* \param img   �����Ӱ��
	* \param text  �ı�����
	* \param pos   �ı�λ��
	* \param color �ı���ɫ
	*
	* \return ���سɹ�������ַ����ȣ�ʧ�ܷ���-1��
	*/

	int putText(cv::Mat &frame, const char    *text, CvPoint pos, CvScalar color);

	/**
	* ������֡���������������ַ���ֹͣ��
	*
	* \param img   �����Ӱ��
	* \param text  �ı�����
	* \param pos   �ı�λ��
	* \param color �ı���ɫ
	*
	* \return ���سɹ�������ַ����ȣ�ʧ�ܷ���-1��
	*/
	int putText(cv::Mat &frame, const wchar_t *text, CvPoint pos, CvScalar color);

	//================================================================  
	//================================================================  

private:

	// �����ǰ�ַ�, ����m_posλ��  

	void putWChar(cv::Mat &frame, wchar_t wc, CvPoint &pos, CvScalar color);

	//================================================================  
	//================================================================  

private:

	FT_Library   m_library;   // �ֿ�  
	FT_Face      m_face;      // ����  

							  //================================================================  
							  //================================================================  

							  // Ĭ�ϵ������������  

	int         m_fontType;
	CvScalar   m_fontSize;
	bool      m_fontUnderline;
	float      m_fontDiaphaneity;

	//================================================================  
	//================================================================  
};

#endif // OPENCV_Cv310Text_2016_11_11_ZMD 