
// TestDlgDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "TestDlg.h"
#include "TestDlgDlg.h"
#include "afxdialogex.h"

#include "defines.h"

//#import "msxml.dll"
#import "MSXML6.dll" rename_namespace(_T("MSXML"))
#include <msxml6.h>
using namespace MSXML;

typedef MSXML::IXMLDOMElementPtr				XMLELEMENT;
typedef MSXML::IXMLDOMDocumentPtr				DOCUMENT;
typedef MSXML::IXMLDOMNodeListPtr				NODELIST;
typedef MSXML::IXMLDOMNodePtr					NODE;
typedef MSXML::IXMLDOMNamedNodeMapPtr			ATTRIBUTE;
typedef MSXML::IXMLDOMProcessingInstructionPtr	PROCESSINGINSTRCT;
typedef MSXML::IXMLDOMParseErrorPtr				PARSEERROR;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace name_test {
	int iname;
}

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestDlgDlg 대화 상자



CTestDlgDlg::CTestDlgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTDLG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BRN_BIT, &CTestDlgDlg::OnBnClickedBrnBit)
	ON_BN_CLICKED(IDC_BRN_BIT2, &CTestDlgDlg::OnBnClickedBrnBit2)
	ON_BN_CLICKED(IDC_BTN_mfc140, &CTestDlgDlg::OnBnClickedBtnmfc140)
	ON_EN_CHANGE(IDC_EDIT_DATA, &CTestDlgDlg::OnEnChangeEditData)
	ON_BN_CLICKED(IDC_BTN_FORMAT, &CTestDlgDlg::OnBnClickedBtnFormat)
	ON_BN_CLICKED(IDC_BTN_MAP, &CTestDlgDlg::OnBnClickedBtnMap)
	ON_BN_CLICKED(IDC_BTN_RACE, &CTestDlgDlg::OnBnClickedBtnRace)
	ON_BN_CLICKED(IDC_BTN_CONSUMER, &CTestDlgDlg::OnBnClickedBtnConsumer)
	ON_BN_CLICKED(IDC_BTN_CONSUMER2, &CTestDlgDlg::OnBnClickedBtnConsumer2)
	ON_BN_CLICKED(IDC_BTN_FUTURE, &CTestDlgDlg::OnBnClickedBtnFuture)
	ON_BN_CLICKED(IDC_BTN_FUTURE2, &CTestDlgDlg::OnBnClickedBtnFuture2)
	ON_BN_CLICKED(IDC_BTN_ASYNC, &CTestDlgDlg::OnBnClickedBtnAsync)
	ON_BN_CLICKED(IDC_BTN_RLEF, &CTestDlgDlg::OnBnClickedBtnRlef)
	ON_BN_CLICKED(IDC_BTN_PAIR, &CTestDlgDlg::OnBnClickedBtnPair)
	ON_BN_CLICKED(IDC_BTN_TUPLE, &CTestDlgDlg::OnBnClickedBtnTuple)
	ON_BN_CLICKED(IDC_BTN_LAMDA, &CTestDlgDlg::OnBnClickedBtnLamda)
	ON_BN_CLICKED(IDC_BTN_LAMDA_FIND, &CTestDlgDlg::OnBnClickedBtnLamdaFind)
	ON_BN_CLICKED(IDC_BTN_OS, &CTestDlgDlg::OnBnClickedBtnOs)
	ON_BN_CLICKED(IDC_BTN_OSVERSION, &CTestDlgDlg::OnBnClickedBtnOsversion)
	ON_BN_CLICKED(IDC_BTN_HASHKEY, &CTestDlgDlg::OnBnClickedBtnHashkey)
	ON_BN_CLICKED(IDC_BTN_WIN, &CTestDlgDlg::OnBnClickedBtnWin)
	ON_BN_CLICKED(IDC_BTN_ICON, &CTestDlgDlg::OnBnClickedBtnIcon)
	ON_BN_CLICKED(IDC_BTN_PRSFIND, &CTestDlgDlg::OnBnClickedBtnPrsfind)
	ON_BN_CLICKED(IDC_BTN_STDCOPY, &CTestDlgDlg::OnBnClickedBtnStdcopy)
	ON_BN_CLICKED(IDC_BTN_HEX, &CTestDlgDlg::OnBnClickedBtnHex)
	ON_BN_CLICKED(IDC_BTN_CODE, &CTestDlgDlg::OnBnClickedBtnCode)
	ON_BN_CLICKED(IDC_BTN_IE, &CTestDlgDlg::OnBnClickedBtnIe)
	ON_BN_CLICKED(IDC_BTN_INT2STR, &CTestDlgDlg::OnBnClickedBtnInt2str)
	ON_BN_CLICKED(IDC_BTN_REMOVEICON, &CTestDlgDlg::OnBnClickedBtnRemoveicon)
	ON_BN_CLICKED(IDC_BTN_CEF, &CTestDlgDlg::OnBnClickedBtnCef)
END_MESSAGE_MAP()


// CTestDlgDlg 메시지 처리기

BOOL CTestDlgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestDlgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTestDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestDlgDlg::OnBnClickedBrnBit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int xval = 0x2a;
	int xdata = 0x08;

	int iret = xval & xdata;
	if (xval & xdata)
		TRACE("TRUE");
	else
		TRACE("FALSE");
}

double RoundDown(double data) //매체수수료(절삭)
{
	return ((int)((data * 0.1)) / 0.1);
}

void CTestDlgDlg::OnBnClickedBrnBit2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double dMaip{}, m_dMass{}, m_dSave{}, symt{};
	m_dMass = 0.0010;
	CString m_maip;
	m_maip = "5690000";
	dMaip = atof(m_maip) + RoundDown((atof(m_maip) + symt) * m_dMass) + m_dSave;//매입가
}


void CTestDlgDlg::OnBnClickedBtnmfc140()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileFind ff;
	CString strpath, strfile;
	((CWnd*)GetDlgItem(IDC_EDIT_DATA))->GetWindowText(strfile);
	strfile.Format("C:\\Windows\\System32\\%s", strfile);

	if (ff.FindFile(strfile))
	{
		AfxMessageBox("find!!!");
	}
	else
	{
		AfxMessageBox("no find!!!");
	}
}


void CTestDlgDlg::OnEnChangeEditData()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

inline CString FORMAT(const TCHAR* formatString, ...)
{
	CString s;
	va_list valist;
	va_start(valist, formatString);
	s.FormatV(formatString, valist);
	va_end(valist);
	return s;
}

void CTestDlgDlg::OnBnClickedBtnFormat()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str = FORMAT("%s|%s|%s|%s", "1", "2", "3", "4");
}



using _hjcode = struct hjcodex;
void CTestDlgDlg::OnBnClickedBtnMap()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	std::map <CString, _hjcode*> _mapCODEx;
	std::vector<_hjcode*> _vETNx;
	std::map<CString, std::pair<CString, int>> _mapACODE;
	std::map<CString, CString>			      _mapNAME;

	CFile	file;
	CString	string = AxStd::FORMAT("%s", "hjcode3.dat");
	if (AxStd::isFileExist(string))
	{
		if (!file.Open(string, CFile::modeRead | CFile::typeBinary | CFile::shareDenyNone))
			return;

		const int  size = gsl::narrow_cast<int>(file.GetLength());
		m_hcB = std::make_unique<char[]>(size + 1);
		const int len = file.Read(m_hcB.get(), size);
		file.Close();

		if (size > len)
		{
			m_hcB.reset();
			return;
		}

		const int count = len / sizeof(struct hjcodex);
		struct	hjcodex* hjc = (struct hjcodex*)m_hcB.get();

		for (int ii = 0; ii < count; ii++, hjc++)
		{
			CString sCode = CString(hjc->code, HCodeLen).Mid(1);
			_mapCODEx.emplace(std::move(sCode), hjc);
			if (hjc->ssgb == jmELW)
				continue;

			if (hjc->ssgb == jmETN)	//2014.10.28 KSJ ETN 추가
			{
				_vETNx.emplace_back(hjc);
				continue;
			}

			_mapACODE.emplace(std::move(sCode), std::move(std::make_pair(CString(hjc->hnam, HNameLen).Mid(1).Trim(), 0)));
			_mapNAME.emplace(std::move(CString(hjc->hnam, HNameLen).Mid(1).Trim()), std::move(sCode));
		} //for

	} //if

	std::map<CString, struct hjcodex*> _mapCODE;
	auto future = std::async([&]() {
		for (auto mt : _mapCODEx)
			_mapCODE.emplace(mt);
		});

	const std::chrono::milliseconds wtime(100);
	while (future.wait_for(wtime) != std::future_status::ready)
		AxStd::_Msg("Thread runing");

	std::vector<hjcodex*> vData;
	for_each(_mapCODE.begin(), _mapCODE.end(), [&vData](auto item) {
		/*if (item.second->kosd == jmKOSPI &&
			item.second->ssgb != jmSINJU &&
			item.second->ssgb != jmSINJS &&
			item.second->ssgb != jmHYFND &&
			item.second->ssgb != jmELW &&
			item.second->ssgb != jmFOREIGN)*/
		vData.emplace_back(item.second);
		});
}

void worker(int& counter)
{
	for (int i = 0; i < 10000; i++)
		counter += 1;
}
void workerWm(int& result, std::mutex& m)
{
	for (int i = 0; i < 10000; i++)
	{
		m.lock();
		result += 1;
		m.unlock();
	}
}

void CTestDlgDlg::OnBnClickedBtnRace()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int  counter = 0;

	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++)
	{
		workers.push_back(std::thread(worker, std::ref(counter)));
	}

	for (int i = 0; i < 4; i++)
	{
		workers[i].join();
	}

	CString stmp;
	stmp.Format("%d", counter);
	TRACE(stmp);


	counter = 0;
	std::mutex m;
	std::vector<std::thread> workerWms;
	for (int i = 0; i < 4; i++)
	{
		workerWms.push_back(std::thread(workerWm, std::ref(counter), std::ref(m)));
	}

	for (int i = 0; i < 4; i++)
	{
		workerWms[i].join();
	}

	stmp.Format("%d", counter);
	TRACE(stmp);
}


void producer(std::queue<std::string>* downloaded_pages, std::mutex* m, int index)
{
	CString slog;
	for (int i = 0; i < 5; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "웹사이트 : " + std::to_string(i) + " from thread(" + std::to_string(index) + ")";
		slog.Format("+++++ producer [%s]\n", content.c_str());
		OutputDebugString(slog);
		m->lock();
		downloaded_pages->push(content);
		m->unlock();
	}
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed)
{
	//전체 처리하는 페이지 개수가 5 * 5 = 25 개
	CString slog;
	while (*num_processed < 25)
	{
		m->lock();
		if (downloaded_pages->empty())
		{
			m->unlock();
			std::this_thread::sleep_for(std::chrono::microseconds(10));
			continue;
		}

		//맨 앞의 페이지를 읽고 대기 목록에서 제거한다.
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		m->unlock();

		//content를 처리한다.
		slog.Format("----consumer %s----\n", content.c_str());
		//	OutputDebugString(slog);
		std::this_thread::sleep_for(std::chrono::microseconds(80));
	}
}


void CTestDlgDlg::OnBnClickedBtnConsumer()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	std::queue<std::string> downloaded_pages;
	std::mutex m;

	std::vector<std::thread> producers;
	for (int i = 0; i < 5; i++)
	{
		producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1));
	}

	int num_processed = 0;
	std::vector<std::thread> consumers;

	for (int i = 0; i < 3; i++)
	{
		consumers.push_back(std::thread(consumer, &downloaded_pages, &m, &num_processed));
	}

	for (int i = 0; i < 5; i++)
		producers[i].join();

	for (int i = 0; i < 3; i++)
		consumers[i].join();

}

void producer_c(std::queue<std::string>* downloaded_pages, std::mutex* m, int index, std::condition_variable* cv)
{
	for (int i = 0; i < 5; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "웹사이트 :" + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		cv->notify_one();
	}
}

void consumer_c(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed, std::condition_variable* cv)
{
	CString slog;
	while (*num_processed < 25)
	{
		std::unique_lock<std::mutex> lk(*m);
		cv->wait(
			lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; }
		);
		if (*num_processed == 25)
		{
			lk.unlock();
			return;
		}

		//맨앞의 페이지를 읽고 대기 목록에서 제거한다.
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		//content를 처리한다.
		slog.Format("----consumer [%s]--", content.c_str());
		OutputDebugString(slog);
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

void CTestDlgDlg::OnBnClickedBtnConsumer2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	std::queue <std::string> downloaded_pages;
	std::mutex m;
	std::condition_variable cv;

	std::vector<std::thread> producers;
	for (int i = 0; i < 5; i++) {
		producers.push_back(
			std::thread(producer_c, &downloaded_pages, &m, i + 1, &cv));
	}

	int num_processed = 0;
	std::vector<std::thread> consumers;
	for (int i = 0; i < 3; i++) {
		consumers.push_back(
			std::thread(consumer_c, &downloaded_pages, &m, &num_processed, &cv));
	}
	for (int i = 0; i < 5; i++) {
		producers[i].join();
	}

	cv.notify_all();

	for (int i = 0; i < 3; i++) {
		consumers[i].join();
	}


}

void fworker(std::promise<string>* p)
{//약속을 이행하는 모습 해당 결과는 future 에 들어간다.
	p->set_value("some data");
}

//future 
void CTestDlgDlg::OnBnClickedBtnFuture()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	std::promise<string> p;

	//미래에 string 데이터를 돌려 주겠다는 약속
	std::future<string> data = p.get_future();
	std::thread t(fworker, &p);

	//미래에 약속된 데이터를 받을 때 까지 기다린다.
	data.wait(); //이코드가 실행되면 

	//wait 이 리턴했다는 뜻이 future에 데이터가 준비되었다는 의미

	CString stmp;
	stmp.Format("------[%s] ---- - \n", data.get().c_str());
	t.join();

}


void pcworker(std::promise<string>* p)
{
	try
	{
		throw std::runtime_error("some error");
	}
	catch (...)
	{
		p->set_exception(std::current_exception());
	}
}


void CTestDlgDlg::OnBnClickedBtnFuture2()  //생산자 소비자 패턴을  future-promise로 구현
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	std::promise<string> p;

	std::future<string> data = p.get_future();

	std::thread t(pcworker, &p);

	data.wait();

	try
	{
		data.get();
	}
	catch (const std::exception& e)
	{
		CString slog;
		slog.Format("except [%s]", e.what());
	}
}




int test_sum(const std::vector<int>& v, int start, int end)
{
	int total = 0;

	for (int i = start; i < end; i++)
	{
		total += v[i];
	}
	return total;
}

int parallel_sum(const std::vector<int>& v)
{
	std::future<int> lower_half_future =
		std::async(std::launch::async, test_sum, cref(v), 0, v.size() / 2);

	int upper_half = test_sum(v, v.size() / 2, v.size());

	return lower_half_future.get() + upper_half;
}

void CTestDlgDlg::OnBnClickedBtnAsync()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	std::vector<int> v;
	v.reserve(1000);

	for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i + 1);
	}

	int result;
	result = parallel_sum(v);


	std::vector<std::pair<CString, CString>> _va;

	CString stmp, stemp;
	for (int ii = 0; ii < 100; ii++)
	{
		stmp.Format("%d", ii);
		stemp.Format("%d", ii + 1);
		_va.emplace_back(std::make_pair(stmp, stemp));
	}

	std::vector<std::tuple<int, CString, CString>> _vta;
	int i = 0;
	auto future = std::async([&]() {
		for (auto mt : _va)
			_vta.emplace_back(std::make_tuple(i++, mt.first, mt.second));
		});

	const std::chrono::milliseconds wtime(100);
	while (future.wait_for(wtime) != std::future_status::ready)
		AxStd::_Msg("Thread runing");


}

class A
{
public:
	int idata;

	A(int ival) { idata = ival; }
	A(const  A& a) { idata = a.idata; }
};


class MyString {
	char* string_content;  // 문자열 데이터를 가리키는 포인터
	int string_length;     // 문자열 길이

	int memory_capacity;  // 현재 할당된 용량

public:
	MyString();

	// 문자열로 부터 생성
	MyString(const char* str);

	// 복사 생성자
	MyString(const MyString& str);

	void reserve(int size);
	MyString operator+(const MyString& s);
	~MyString();

	int length() const;

	void print();
	void println();
};

MyString::MyString() {
	std::cout << "생성자 호출 ! " << std::endl;
	string_length = 0;
	memory_capacity = 0;
	string_content = nullptr;
}

MyString::MyString(const char* str) {
	std::cout << "생성자 호출 ! " << std::endl;
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
	std::cout << "복사 생성자 호출 ! " << std::endl;
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];

		if (prev_string_content != nullptr) delete[] prev_string_content;
	}
}
MyString MyString::operator+(const MyString& s) {
	MyString str;
	str.reserve(string_length + s.string_length);
	for (int i = 0; i < string_length; i++)
		str.string_content[i] = string_content[i];
	for (int i = 0; i < s.string_length; i++)
		str.string_content[string_length + i] = s.string_content[i];
	str.string_length = string_length + s.string_length;
	return str;
}
int MyString::length() const { return string_length; }
void MyString::print() {
	for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}
void MyString::println() {
	for (int i = 0; i != string_length; i++) std::cout << string_content[i];

	std::cout << std::endl;
}

int main() {
	MyString str1("abc");
	MyString str2("def");
	std::cout << "-------------" << std::endl;
	MyString str3 = str1 + str2;
	str3.println();
}

void CTestDlgDlg::OnBnClickedBtnRlef()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	A a(1);
	A b(a);
}


void CTestDlgDlg::OnBnClickedBtnPair()
{
	std::map<CString, std::pair<CString, int>> _mapACODE;
	std::map<CString, CString> _mapNAME;

	CFile	file;
	CString	string = AxStd::FORMAT("%s", "hjcode3.dat");
	if (AxStd::isFileExist(string))
	{
		if (!file.Open(string, CFile::modeRead | CFile::typeBinary | CFile::shareDenyNone))
			return;

		const int size = gsl::narrow_cast<int>(file.GetLength());
		m_hcB = std::make_unique<char[]>(size + 1);
		const int len = file.Read(m_hcB.get(), size);
		file.Close();

		if (size > len)
		{
			m_hcB.reset();
			return;
		}

		const int count = len / sizeof(struct hjcodex);
		struct hjcodex* hjc = (struct hjcodex*)m_hcB.get();

		for (int ii = 0; ii < count; ii++, hjc++)
		{
			CString sCode = CString(hjc->code, HCodeLen).Mid(1);
			_mapACODE.emplace(std::move(sCode), std::move(std::make_pair(CString(hjc->hnam, HNameLen).Mid(1).Trim(), 0)));
			_mapNAME.emplace(std::move(CString(hjc->hnam, HNameLen).Mid(1).Trim()), std::move(sCode));
		}

	}
}
//------------------------------------------------------------------------------------------------------------------------------------------
struct _efopcode
{
	char	type[1]{};			/*데이터 타입*/
	/*'1':운용사별*/
	/*'2':테마별*/
	/*'3':국내외 구분별*/
	/*'4':종목별*/
	char	code[6]{};			/*종목코드*/
	char	hnam[39]{};			/*종목명*/
	char	opcd[6]{};			/*운용사 코드*/
	char	etfm[1]{};			/*테마코드*/
	char	etfl[1]{};			/*국내외 구분*/
};

struct _efopitem
{
	char	type[1]{};			/*데이터 타입*/
	/*'1':운용사별*/
	/*'2':테마별*/
	/*'3':국내외 구분별*/
	/*'4':종목별*/
	char	opcd[6]{};			/*운용사 코드*/
	char	hnam[30]{};			/*운용사 한글약명*/
	char	lnfd[1]{};			/*라인피드*/

	//	_efopcode *efopcode;
};


struct _efoptema
{
	char	type[1]{};			/*데이터 타입*/
	/*'1':운용사별*/
	/*'2':테마별*/
	/*'3':국내외 구분별*/
	/*'4':종목별*/
	char	tmcd[1]{};			/*테마코드*/
	char	tmnm[20]{};			/*테마명*/
	char	lnfd[1]{};			/*라인피드*/
};

struct _efopfore
{
	char	type[1]{};			/*데이터 타입*/
	/*'1':운용사별*/
	/*'2':테마별*/
	/*'3':국내외 구분별*/
	/*'4':종목별*/
	char	frcd[1]{};			/*국내외 구분('D':국내, 'F':해외)*/
	char	frnm[10]{};			/*국내외 구분명*/
	char	lnfd[1]{};			/*라인피드*/
};

//void test_compare(std::vector<std::pair<CString, CString>> a, std::vector<std::pair<CString, CString>> b)
template <typename T>
void test_compare()
{
	CString tmp, temp;
	bool operator()(const T & a, const T & b)  const {}
}

void CTestDlgDlg::OnBnClickedBtnTuple()
{
	std::vector<std::tuple<char, CString, CString>>	_vETFitem;
	std::vector<std::tuple<char, char, CString>>	_vETFtema;
	std::vector<std::tuple<char, char, CString>>	_vETFfore;
	std::vector<std::tuple<char, CString, CString, CString, char, char>> _vETFcode;

	CString sfile;
	sfile.Format("%s", "efcode.dat");

	CStdioFile cfile(sfile, CFile::modeRead);

	CString line;
	while (cfile.ReadString(line))
	{
		switch (const char gubn = line.GetAt(0); gubn)
		{
		case '1':
		{
			const _efopitem* efopitem = (struct _efopitem*)line.GetBuffer();
			_vETFitem.emplace_back(std::move(std::tuple(efopitem->type[0],
				CString(efopitem->opcd, sizeof(efopitem->opcd)).Trim(),
				CString(efopitem->hnam, sizeof(efopitem->hnam)).Trim())));
		}
		break;
		case '2':
		{
			const _efoptema* efoptema = (struct _efoptema*)line.GetBuffer();
			_vETFtema.emplace_back(std::move(std::tuple(efoptema->type[0],
				efoptema->tmcd[0],
				CString(efoptema->tmnm, sizeof(efoptema->tmnm)).Trim())));
		}
		break;
		case '3':
		{
			const _efopfore* efopfore = (struct _efopfore*)line.GetBuffer();
			_vETFfore.emplace_back(std::move(std::tuple(efopfore->type[0], efopfore->frcd[0],
				CString(efopfore->frnm, sizeof(efopfore->frnm)).Trim())));
		}
		break;
		case '4':
		{
			const _efopcode* efopcode = (struct _efopcode*)line.GetBuffer();
			_vETFcode.emplace_back(std::move(std::tuple(efopcode->type[0],
				CString(efopcode->code, sizeof(efopcode->code)).Trim(),
				CString(efopcode->hnam, sizeof(efopcode->hnam)).Trim(),
				CString(efopcode->opcd, sizeof(efopcode->opcd)).Trim(),
				efopcode->etfm[0],
				efopcode->etfl[0]
			)));
		}
		break;
		}
	}

	std::vector <std::pair<CString, CString>> _vData;
	for_each(_vETFcode.begin(), _vETFcode.end(), [&](const auto item) {
		auto [type, code, hnam, opcd, etfm, etfl] = item;
		_vData.emplace_back(std::move(std::make_pair(code, hnam)));
		});

	std::sort(_vData.begin(), _vData.end());

	CString name;
	for_each(_vData.begin(), _vData.end(), [&](const auto item) {
		name = item.second;
		auto [CString, CSting] = item;
		name.MakeUpper();
		});

	auto item = _vData.at(0);
	CString strdata;
	strdata = std::get<0>(item);
	/*
	for_each(vSearch.begin(), vSearch.end(), [&](const auto item){
		name = item.second;
		name.MakeUpper();
		sName.MakeUpper();
		if (name.Find(sName) >= 0)
			vText.emplace_back(item);
	});
	*/
}

template <typename Iter>
void testprint(Iter begin, Iter end)
{
	OutputDebugString("--------------------------\n");
	CString stmp;
	while (begin != end)
	{
		stmp.Format(" %d\n", *begin);
		OutputDebugString(stmp);
		begin++;
	}
}

void CTestDlgDlg::OnBnClickedBtnLamda()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	auto func = [](int i) { return i % 2 == 1; };
//	auto ret = func(4);


	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	testprint(vec.begin(), vec.end());

	int num_erased = 0;
	vec.erase(std::remove_if(vec.begin(), vec.end(),
		[&num_erased](int i) {
			if (num_erased >= 2)
				return false;
			else if (i % 2 == 1) {
				num_erased++;
				return true;
			}
			return false;
		}),
		vec.end());
	testprint(vec.begin(), vec.end());


}

void getHjcodeMap(std::map<CString, _hjcode>& map)
{
	std::map <CString, _hjcode*> _mapCODEx;
	std::vector<_hjcode*> _vETNx;
	std::map<CString, std::pair<CString, int>> _mapACODE;
	std::map<CString, CString>			      _mapNAME;
	std::unique_ptr<char[]> m_hcB;

	CFile	file;
	CString	string = AxStd::FORMAT("%s", "hjcode3.dat");
	if (AxStd::isFileExist(string))
	{
		if (!file.Open(string, CFile::modeRead | CFile::typeBinary | CFile::shareDenyNone))
			return;

		const int  size = gsl::narrow_cast<int>(file.GetLength());
		m_hcB = std::make_unique<char[]>(size + 1);
		const int len = file.Read(m_hcB.get(), size);
		file.Close();

		if (size > len)
		{
			m_hcB.reset();
			return;
		}

		const int count = len / sizeof(struct hjcodex);
		struct	hjcodex* hjc = (struct hjcodex*)m_hcB.get();

		for (int ii = 0; ii < count; ii++, hjc++)
		{
			CString sCode = CString(hjc->code, HCodeLen).Mid(1);
			_mapCODEx.emplace(std::move(sCode), hjc);

			map.emplace(sCode, *hjc);

			//	_mapACODE.emplace(std::move(sCode), std::move(std::make_pair(CString(hjc->hnam, HNameLen).Mid(1).Trim(), 0)));
			//	_mapNAME.emplace(std::move(CString(hjc->hnam, HNameLen).Mid(1).Trim()), std::move(sCode));
		} //for
	} //if

	//std::map<CString, struct hjcodex*> _mapCODE;
	//auto future = std::async([&]() {
	//	for (auto mt : _mapCODEx)
	//		_mapCODE.emplace(mt);
	//	});

	//const std::chrono::milliseconds wtime(100);
	//while (future.wait_for(wtime) != std::future_status::ready)
	//	AxStd::_Msg("Thread runing");

}

void CTestDlgDlg::OnBnClickedBtnLamdaFind()
{
	std::map<CString, _hjcode> _map;
	getHjcodeMap(_map);
	//strdata = std::get<0>(item);const auto hjc
	std::vector< _hjcode> _vt;
	CString name;
	for (auto& item : _map)
	{
		_hjcode hjc = item.second;
		name.Format("%s", hjc.hnam);

		if( name.Find("타") >= 0)
		{
			_vt.emplace_back(std::move(hjc));
		}
	}
	//auto it  = std::remove_if(_map.begin(), _map.end(), [&](const auto item)->bool{
	//		name = CString(hjc->hnam, sizeof(hjc->hnam)).Mid(1);
	//	
	//		CString strUpperS, strUpperO;
	//		strUpperS = cName;
	//		strUpperO = name.GetAt(ii);
	//		strUpperS.MakeUpper();
	//		strUpperO.MakeUpper();

	//		if (strUpperS != strUpperO)
	//			return true;
	//		return false;
	//	});

}
#include <stdio.h>
typedef BOOL(WINAPI* LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
LPFN_ISWOW64PROCESS fnIsWow64Process;
void CTestDlgDlg::OnBnClickedBtnOs()
{
	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
	
	if (fnIsWow64Process == NULL)
		AfxMessageBox("check fail");

	bool bProcess64 = false;
#if defined(_WIN64)
	bProcess64 = FALSE;
#elif defined(_WIN32)
	BOOL f64 = FALSE;
	bProcess64 = fnIsWow64Process(GetCurrentProcess(), &f64) && f64;
#endif

}


void CTestDlgDlg::OnBnClickedBtnOsversion()
{
	/*OSVERSIONINFOEX info{};
	SYSTEM_INFO sysinfo{};
	MEMORYSTATUS memStatus{};

	info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx((OSVERSIONINFO *)&info);*/
}

UINT AFXAPI Hashdata(LPCSTR key)
{
	UINT nHash = 0;
	while (*key)
		nHash = (nHash << 5) + nHash + *key++;
	return nHash;
}

void CTestDlgDlg::OnBnClickedBtnHashkey()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString sname;
	sname = "131122";
	CString sdata;
	sdata.Format("%08u", Hashdata((LPCSTR)sname));
	
	//	sdata.Format("%08u", HashKey((LPCSTR)sname));
	int idata = 300000000;
}


void CTestDlgDlg::OnBnClickedBtnWin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	long data = (long)this;
	CString sdata;
//	sdata.Format("%x", data); 
//	int idata = sizeof(CWnd*);
	((CWnd*)data)->SendMessage(WM_CLOSE, 0, 0);
}

// LPTSTR pszFilePath : 실행파일경로  및 파일명.확장자
// LPTSTR pszTitle :  \\파일명.lnk
// LPTSTR pszDescription : 표시할 툴팁
// BOOL bDesktop : 바탕화면 생성 유무 TRUE., FALSE
// BOOL bQuickLanch : quicklaunch 생성 유무 TRUE., FALSE
// BOOL bStartMenu : 시작메뉴 생성 유무 TRUE., FALSE
// BOOL bOverWrite :  기존 구성 덮어쓰기 유무 TRUE., FALSE
#include <shlobj_core.h>
BOOL CTestDlgDlg::CreateShortcut(LPTSTR pszFilePath, LPTSTR pszTitle, LPTSTR pszDescription, BOOL bDesktop, BOOL bQuickLanch, BOOL bStartMenu, BOOL bOverWrite)
{
	char pBuffer[MAX_PATH];
	SHGetSpecialFolderPath(GetSafeHwnd(), (LPSTR)pBuffer, CSIDL_DESKTOP, 0);
	//SHGETFOLDERPATH fnShGetFolderPath;
/*


	if (!bDesktop && !bQuickLanch && !bStartMenu)  
		return TRUE;


	HMODULE hModule = LoadLibrary("SHFOLDER.DLL");

	if (hModule != NULL) {

		fnShGetFolderPath = (SHGETFOLDERPATH)GetProcAddress(hModule, "SHGetFolderPathA");


		if (fnShGetFolderPath == NULL) {

			FreeLibrary(hModule);

			//MessageBox("아이콘 등록에 실패하였습니다. Shell Version이 낮습니다.", "에러", MB_ICONSTOP);

			return FALSE;

		}

	}



	//  실제 대상파일이 존재하는지 체크하는 루틴추가.

	//if( !IsFileExist( pszFilePath ))  return TRUE;



	CString strTempPath;

	// 아이콘의 이름 설정이 안되었을 경우 기본 이름으로 설정 : *.exe의 바로가기

	if (pszTitle == NULL) {

		TCHAR szFileName[MAX_PATH];

		memset(szFileName, 0x00, sizeof(szFileName));



		TCHAR szFilePath[MAX_PATH];

		memset(szFilePath, 0x00, sizeof(szFilePath));



		lstrcpy(szFilePath, pszFilePath);



		TCHAR* pszToken;

		pszToken = strtok(szFilePath, _T("\\"));



		while (pszToken != NULL) {

			lstrcpy(szFileName, pszToken);

			pszToken = strtok(NULL, _T("\\"));

		}



		strTempPath.Format(_T("\\%s%s"), szFileName, _T("의 바로가기.lnk"));

		pszTitle = strTempPath.GetBuffer(strTempPath.GetLength());

	}



	BOOL bResult = TRUE;



	HRESULT hResult;

	IShellLink* pShellLink;

	IPersistFile* pPersistFile;



	TCHAR szDesktopPath[MAX_PATH];

	TCHAR szQuickLanchPath[MAX_PATH];

	TCHAR szStartMenuPath[MAX_PATH];



	memset(szDesktopPath, 0x00, sizeof(szDesktopPath));

	memset(szQuickLanchPath, 0x00, sizeof(szQuickLanchPath));

	memset(szStartMenuPath, 0x00, sizeof(szStartMenuPath));



	// 바탕화면 아이콘이 저장될 경로 설정

	//SHGetSpecialFolderPath(NULL, szDesktopPath, MAX_PATH );

	if (FAILED(fnShGetFolderPath(NULL, CSIDL_DESKTOP, NULL, 0, szDesktopPath)))  return FALSE;

	LPSTR strDesktopPath = lstrcat(szDesktopPath, pszTitle);



	// 빠른 실행 아이콘이 저장될 경로 설정

	if (FAILED(fnShGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, szQuickLanchPath)))  return FALSE;

	LPSTR strQuickLanchPath = lstrcat(szQuickLanchPath, _T("\\Microsoft\\Internet Explorer\\Quick Launch"));

	strQuickLanchPath = lstrcat(szQuickLanchPath, pszTitle);



	// 시작메뉴

	if (FAILED(fnShGetFolderPath(NULL, CSIDL_PROGRAMS, NULL, 0, szStartMenuPath)))  return FALSE;

	LPSTR strStartMenuPath = lstrcat(szStartMenuPath, pszTitle);



	if (!bOverWrite) {

		// 바탕화면 아이콘이 있으면 

		if (IsFileExist((LPCTSTR)strDesktopPath))		bDesktop = FALSE;

		// 빠른실행 아이콘이 있으면 

		if (IsFileExist((LPCTSTR)szQuickLanchPath))		bQuickLanch = FALSE;

		// 시작메뉴  아이콘이 있으면 

		if (IsFileExist((LPCTSTR)szStartMenuPath))		bStartMenu = FALSE;



		if (!bDesktop && !bQuickLanch && !bStartMenu)		return TRUE;

	}



	// COM Object 초기화

	CoInitialize(NULL);



	// IShellLink 객체를 생성하고 포인터를 구함

	hResult = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&pShellLink);



	if (SUCCEEDED(hResult)) {

		// 단축아이콘의 대상체와 설명을 설정한다.



		CString exe_dir_str;

		TCHAR drive[_MAX_DRIVE] = _T(""), dir[_MAX_DIR] = _T("");

		TCHAR fname[_MAX_FNAME] = _T(""), ext[_MAX_EXT] = _T("");

		_tsplitpath(pszFilePath, drive, dir, fname, ext);

		exe_dir_str.Format("%s%s", drive, dir);



		pShellLink->SetPath(pszFilePath);

		pShellLink->SetDescription(pszDescription);

		pShellLink->SetArguments(_T(""));

		pShellLink->SetWorkingDirectory(exe_dir_str);



		// 저장하기 위해 IPersistFile 객체 생성

		hResult = pShellLink->QueryInterface(IID_IPersistFile, (LPVOID*)&pPersistFile);



		// 유니코드로 파일 패스를 변경한 후 저장

		if (SUCCEEDED(hResult)) {



			WORD wszDesktop[MAX_PATH];

			memset(wszDesktop, 0x00, sizeof(wszDesktop));

			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, strDesktopPath, -1, LPWSTR(wszDesktop), MAX_PATH);



			WORD wszQuickLanch[MAX_PATH];

			memset(wszQuickLanch, 0x00, sizeof(wszQuickLanch));

			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, strQuickLanchPath, -1, LPWSTR(wszQuickLanch), MAX_PATH);



			WORD wszStartMenu[MAX_PATH];

			memset(wszStartMenu, 0x00, sizeof(wszStartMenu));

			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, strStartMenuPath, -1, LPWSTR(wszStartMenu), MAX_PATH);





			// shortcut 등록

			if (bDesktop) {

				if (!pPersistFile->Save(LPWSTR(wszDesktop), TRUE))	 bResult = FALSE;

			}



			//Quick Lauch에 등록 

			if (bQuickLanch) {

				if (!pPersistFile->Save(LPWSTR(wszQuickLanch), TRUE))	bResult = FALSE;

			}



			//bStartMenu에 등록 

			if (bStartMenu) {

				if (!pPersistFile->Save(LPWSTR(wszStartMenu), TRUE))	bResult = FALSE;

			}



			pPersistFile->Release();



			// 아이콘 재설정

			::SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST | SHCNF_FLUSH, NULL, NULL);

		}

		pShellLink->Release();



		//COM 해제

		CoUninitialize();

		FreeLibrary(hModule);

		return bResult;
	
	}
	else {

		FreeLibrary(hModule);

	}

	return bResult;
	*/
return FALSE;
}

void CTestDlgDlg::OnBnClickedBtnIcon()
{
	CString strpath;          //  %systemdrive%\users\%username%\desktop
	strpath.Format("del %s",  "\"%systemdrive%\users\%username%\desktop\IBK hot Trading.lnk\"");
	ShellExecute(NULL, _T("open"), "C:\\test.bat", NULL, NULL, SW_SHOWNORMAL);
	//ShellExecute(NULL, strpath, NULL, NULL, NULL, SW_SHOWNORMAL);
	//ShellExecute(NULL, _T("open"), "C:\\test.bat", NULL, NULL, SW_SHOWNORMAL);
	//char pBuffer[MAX_PATH];
	//SHGetSpecialFolderPath(GetSafeHwnd(), (LPSTR)pBuffer, CSIDL_DESKTOP, 0);

	//SHGETFOLDERPATH fnShGetFolderPath;
	//HMODULE hModule = LoadLibrary("SHFOLDER.DLL");
	//if (hModule != NULL) {

	//	fnShGetFolderPath = (SHGETFOLDERPATH)GetProcAddress(hModule, "SHGetFolderPathA");



	//	if (fnShGetFolderPath == NULL) {

	//		FreeLibrary(hModule);

	//		//MessageBox("아이콘 등록에 실패하였습니다. Shell Version이 낮습니다.", "에러", MB_ICONSTOP);

	//		return FALSE;

	//	}

	}
	

#include <TlHelp32.h>

bool GetProcessModule(DWORD dwPID, char* sProcessName,  char* pProcess)
{
	HANDLE        hModuleSnap = NULL;
	MODULEENTRY32 me32 = { 0 };
	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);

	CString stmp;
	stmp.Format("%s", pProcess);
	if (stmp.Find("axis.exe") >= 0)
		TRACE("123");

	if (hModuleSnap == (HANDLE)-1)
		return (FALSE);

	me32.dwSize = sizeof(MODULEENTRY32);
	CString slog;
	//해당 프로세스의 모듈리스트를 루프로 돌려서 프로세스이름과 동일하면
	
	if (Module32First(hModuleSnap, &me32))
	{
		do
		{
			printf("process name : %s\n", me32.szModule);
			slog.Format("[mac] GetProcessModule =[%s] \r\n", me32.szModule);
			//OutputDebugString(slog);
			if (strcmp(me32.szModule, sProcessName) == 0)
			{
				CloseHandle(hModuleSnap);
				return true;
			}
		} while (Module32Next(hModuleSnap, &me32));
	}

	CloseHandle(hModuleSnap);
	return false;
}
//
HANDLE CTestDlgDlg::ProcessFind(char* strProcessName)
{

	HANDLE         hProcessSnap = NULL;
	BOOL           bRet = FALSE;
	PROCESSENTRY32 pe32 = { 0 };
	CString strProcess;

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap == (HANDLE)-1)
		return false;

	pe32.dwSize = sizeof(PROCESSENTRY32);
	CString slog;
	//프로세스가 메모리상에 있으면 첫번째 프로세스를 얻는다
	if (Process32First(hProcessSnap, &pe32))
	{
		BOOL          bCurrent = FALSE;
		MODULEENTRY32 me32 = { 0 };

		do
		{
		//	bCurrent = GetProcessModule(pe32.th32ProcessID, strProcessName, pe32.szExeFile);
			slog.Format("[MAC] [%s] \r\n", pe32.szExeFile);
			OutputDebugString(slog);
			OutputDebugString("\r\n-----------------------------------------------\r\n");
			strProcess.Format("%s", pe32.szExeFile);
			if (strProcess.Find("axis.exe") >= 0)
			{
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
				if (hProcess)
					TerminateProcess(hProcess, 0);
			}
		} while (Process32Next(hProcessSnap, &pe32)); //다음 프로세스의 정보를 구하여 있으면 루프를 돈다.
	}
	CloseHandle(hProcessSnap);

	return NULL;
}

void CTestDlgDlg::OnBnClickedBtnPrsfind()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HANDLE hwnd = ProcessFind("axis.exe");
	if (hwnd)
	{
		TerminateProcess(hwnd, 0);
	}
	CString str;
}


void CTestDlgDlg::OnBnClickedBtnStdcopy()
{
	int inum = 9600;
	CString  stest;
	stest = "1";

	if (stest == "0" && ((inum >= 7600) && (inum <= 9600)))
		TRACE("TEST");


	std::vector<std::shared_ptr<_intersx>> m_inters;
	std::vector<std::shared_ptr<_intersx>> m_Inters;

	CString stmp;
	for (int ii = 0; ii < 10; ii++)
	{
		auto& pdata = m_inters.emplace_back(std::make_unique< _intersx>());
		stmp.Format("%d", ii);
		pdata->code = stmp;
	}


	for (int ii = 0; ii < 2; ii++)
	{
		const auto& vInters = m_inters;
		const int count = 10;
		std::copy(vInters.begin(), vInters.begin() + count, std::back_insert_iterator(m_Inters));
	}
}


void CTestDlgDlg::OnBnClickedBtnHex()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, stemp;
	str = "1234a";
	if ((str.GetAt(0) < '0' || str.GetAt(0) > '9') && (str.GetAt(0) < 'A' || str.GetAt(0) > 'G'))
		OutputDebugString(str);
	OutputDebugString("123");

	for (int ii = 1; ii < str.GetLength(); ii++)
		if ((str.GetAt(ii) < '0' || str.GetAt(ii) > '9') &&
			(str.GetAt(ii) < 'a' || (str.GetAt(ii) > 'z' && str.GetAt(ii) != 's')) &&
			(str.GetAt(ii) < 'A' || (str.GetAt(ii) > 'Z' && str.GetAt(ii) != 'S')))
			return ;
	return ;

	for (int ii = 1; ii < str.GetLength(); ii++)
	{
		stemp.Format("\r\n%c",str.GetAt(ii));
		OutputDebugString(stemp);
		if (str.GetAt(ii) < '0' || str.GetAt(ii) > '9')
			OutputDebugString("!!!!!\r\n");
		if (str.GetAt(ii) < 'a' || (str.GetAt(ii) > 'z' && str.GetAt(ii) != 's'))
			OutputDebugString("#####\r\n");
		if (str.GetAt(ii) < 'A' || (str.GetAt(ii) > 'Z' && str.GetAt(ii) != 'S'))
			OutputDebugString("&&&&\r\n");
	}
	
	
}


void CTestDlgDlg::OnBnClickedBtnCode()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char ch1 = '1';

	switch (ch1)
	{
	case '1':
	case 'D':
	{
		TRACE("123");
	}
	break;
	}
}


void CTestDlgDlg::OnBnClickedBtnIe()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strurl;
	//strurl = "microsoft - edge:"; 
	strurl = "https://www.ibks.com/LoadService.jsp?url=/event/event_overseasExchange.jsp&popup=Y&auth=_q579%3A%2B9%3E%3A%262%3A8%2C%3E%3A%2Ccai%3E%2Clv3%2F%3A%3A%2F8%2F9%3D1909%3B4.jn3g%60p%3B%3D9.q%7B31w%2F%7B9e&keyB_YN=Y&nPro_YN=N&aos_YN=N";
	//strurl += "naver.com";
	ShellExecute(NULL, "open", "chrome.exe" , strurl, NULL, SW_SHOWNORMAL);
	
}

//using namespace name_test;


#define	vtypeMSK	0xf0		
#define	vtypeERR		0x00
#define	vtypeNRM		0x01
#define	vtypeVBX		0x02
#define	vtypeDLL		0x03
#define	vtypeGRX		0x04
#define	vtypeHTM		0x05


void CTestDlgDlg::OnBnClickedBtnInt2str()
{
	int ii = 1;
	int iii = 0;
	double dData = 0.0;
	iii = (int)dData;
	int idata = ii / (int)dData;
	CString str;
	//long ii = MAKELONG(0x05, 36);
	////HIWORD(kind) & 0xff00
	//WORD wd = HIWORD(ii);
	//wd = HIWORD(ii) & 0xff00;
	////iname = 0;
	//
	//int isize = sizeof(WORD);
	//int idata = 0xf0;
	//idata = ~idata;

	//int i = 0;;
	//double d = 0.0;
	// idata = (int)d;
	////if (d == 0)
	////	return;
	// idata = i / d;
	//CString str;

	//int  type = 33;
	//idata = type & ~vtypeMSK;
	//switch (type & ~vtypeMSK)
	//{
	//case vtypeNRM: 
	//	TRACE("0");
	//	break;
	//case vtypeDLL:  
	//	TRACE("1");
	//	break;
	//case vtypeGRX: 
	//	TRACE("2");
	//	break;
	//case vtypeVBX: 
	//	TRACE("3");
	//	break;
	//}

	//switch (type )
	//{
	//case vtypeNRM:
	//	TRACE("0");
	//	break;
	//case vtypeDLL:
	//	TRACE("1");
	//	break;
	//case vtypeGRX:
	//	TRACE("2");
	//	break;
	//case vtypeVBX:
	//	TRACE("3");
	//	break;
	//}

	
	//int val{};
	//char dst[32]{}, src[32]{}, * buf = nullptr, * str = nullptr;

	//int len{};
	//len = sprintf(src, "%d", val);

	//if (val < 0)
	//{
	//	dst[0] = '-';
	//	str = &src[1];
	//	buf = &dst[1];
	//	--len;
	//}
	//else
	//{
	//	str = &src[0];
	//	buf = &dst[0];
	//}

	//switch ((len - 1) % 3) 
	//{
	//case 3: // fake label to make gcc happy 
	//	while (*str) {
	//		*buf++ = ',';
	//case 2: *buf++ = *str++;
	//case 1: *buf++ = *str++;
	//case 0: *buf++ = *str++;
	//	}
	//}
	//*buf = '\0';
}

#include <Windows.h>
#include <VersionHelpers.h>  // Windows 버전 확인을 위한 헤더 파일
#include <Psapi.h>
void CTestDlgDlg::OnBnClickedBtnRemoveicon()
{




		// 바탕화면 핸들 검색
		HWND hDesktopWnd = ::GetDesktopWindow();

		// 바탕화면의 첫 번째 아이콘 핸들 검색
		HWND hIconWnd = ::FindWindowEx(hDesktopWnd, NULL, "WorkerW", NULL);
		if (hIconWnd)
		{
			// 바탕화면 창 핸들의 부모 핸들 검색
			HWND hDesktopParent = ::GetParent(hDesktopWnd);

			// 부모 핸들의 프로세스 ID 검색
			DWORD dwProcessId = 0;
			::GetWindowThreadProcessId(hDesktopParent, &dwProcessId);

			// 프로세스 핸들 검색
			HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, dwProcessId);
			if (hProcess)
			{
				// 프로세스의 모듈 핸들 검색
				HMODULE hModule = nullptr;
				DWORD dwNeeded = 0;
				if (::EnumProcessModules(hProcess, &hModule, sizeof(hModule), &dwNeeded))
				{
					// 모듈 경로 검색
					WCHAR szPath[MAX_PATH] = { 0 };
					::GetModuleFileNameExW(hProcess, hModule, szPath, MAX_PATH);

					// Windows 탐색기 프로세스인지 확인
				//	if (::wcsstr(szPath, "explorer.exe"))
					{
						// 바탕화면 아이콘 리스트 뷰 핸들 검색
						HWND hIconListView = ::FindWindowEx(hIconWnd, NULL, "SysListView32", NULL);
						if (hIconListView)
						{
							// 바탕화면 아이콘 핸들 검색
							HWND hTargetIcon = ::FindWindowEx(hIconListView, NULL, "SysListView32", "IBK hot Trading");
							if (hTargetIcon)
							{
								// 아이콘 핸들에 대해 삭제 메시지 보내기
								::SendMessage(hIconListView, LVM_DELETEITEM, 0, (LPARAM)hTargetIcon);
							}
						}
					}
				}
				::CloseHandle(hProcess);
			}
		}


}



void CTestDlgDlg::OnBnClickedBtnCef()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
