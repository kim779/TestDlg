#pragma once
struct _intersx
{
	char	gubn = '0';		// ���񱸺�	0:none, 1:����, 2:����, 3:�ɼ�, 4:�����ֽĿɼ�, 5:����	
	CString code;			// �����ڵ�
	CString name;			// �����
	CString	xprc;			// �����ܰ�
	CString	xnum;			// ��������
	CString	xupnum;			// ���� �ֽļ�
	char	bookmark = '0';		// �ϸ�ũ
	char	futureGubn{};		// �ſ�Ÿ� ����
	double  creditPrc{};		// �ſ�ݾ�
	double	maeipPrc{};		// ���Աݾ�

	void copy(void* item);

	void operator=(struct _intersx& ref)
	{
		code = ref.code;
		name = ref.name;
		gubn = ref.gubn;
		xprc = ref.xprc;
		xnum = ref.xnum;
		xupnum = ref.xupnum;
		bookmark = ref.bookmark;
		futureGubn = ref.futureGubn;
		creditPrc = ref.creditPrc;
		maeipPrc = ref.maeipPrc;
	}

	void empty()
	{
		code.Empty();
		name.Empty();
		gubn = '0';
		xprc.Empty();
		xnum.Empty();
		xupnum.Empty();
		bookmark = '0';
		futureGubn = '0';
		creditPrc = 0;
		maeipPrc = 0;
	}
};