#pragma once
struct _intersx
{
	char	gubn = '0';		// 종목구분	0:none, 1:현물, 2:선물, 3:옵션, 4:개별주식옵션, 5:지수	
	CString code;			// 종목코드
	CString name;			// 종목명
	CString	xprc;			// 보유단가
	CString	xnum;			// 보유수량
	CString	xupnum;			// 상장 주식수
	char	bookmark = '0';		// 북마크
	char	futureGubn{};		// 신용매매 구분
	double  creditPrc{};		// 신용금액
	double	maeipPrc{};		// 매입금액

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