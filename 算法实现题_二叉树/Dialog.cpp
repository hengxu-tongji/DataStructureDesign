#include "wx/wx.h"
#include "wx/button.h"
#include <wx/sizer.h>
#include <wx/gbsizer.h>
#include "BiTree.h"

// ����Ӧ�ó�����
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// ������������
class MyFrame : public wxFrame
{
public:
    // ��������Ĺ��캯��
    MyFrame(const wxString& title);
    
    // �¼�������
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton_1(wxCommandEvent& event);

    wxTextCtrl* tc0;

private:
    // �����¼���
    DECLARE_EVENT_TABLE()
};

// ������һ�оͿ���ʹ�� MyApp& wxGetApp()��
DECLARE_APP(MyApp)

// ����wxWidgets��Ӧ�ó������ĸ���
IMPLEMENT_APP(MyApp)

// ��ʼ������
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(wxT("������"));
    frame->Show(true);
    return true;
}

enum {
    wxID111,
};

// MyFrame����¼���
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("�����������ɵ������������У��ڲ������һ���ַ���ʾ���ս����#��ʾ��"),
        wxVERSION_STRING);

    wxMessageBox(msg, wxT("��δ�������"),
        wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
    // �ͷ�������
    Close();
}



void MyFrame::OnButton_1(wxCommandEvent& event)
{
    int iddd = event.GetId();
    if (iddd == wxID111) {
        wxString s(tc0->GetValue());
        char cs[100];
        strcpy(cs, s.mb_str());
        int i = 0;
        CreateBiTree(T, P,i,cs);

        wxString msg;
        msg.Printf(wxT("���ɳɹ���"),
            wxVERSION_STRING);
        wxMessageBox(msg, wxT("���ɶ�����"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 10) {
        wxString abc;
        wxString msg;
        PreOrderTraverse(T,abc);
        msg.Printf(wxT("����������Ϊ��"),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("�������"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 2) {
        wxString abc;
        wxString msg;
        InOrderTraverse(T,abc);
        msg.Printf(wxT("����������Ϊ��"),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("�������"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 3) {
        wxString abc;
        wxString msg;
        PosOrderTraverse(T,abc);
        msg.Printf(wxT("����������Ϊ��"),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("�������"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 4) {
        wxString msg;
        PreOrderThreading(Thrt, T);
        msg.Printf(wxT("������������ɣ�"),
            wxVERSION_STRING);
        wxMessageBox(msg, wxT("����������"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 5) {
        wxString msg;
        InOrderThreading(Thrt,T);
        msg.Printf(wxT("������������ɣ�"),
            wxVERSION_STRING);
        wxMessageBox(msg, wxT("����������"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 6) {
        wxString msg;
        msg.Printf(wxT("������������ɣ�"),
            wxVERSION_STRING);
        wxMessageBox(msg, wxT("����������"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 7) {
        wxString abc;
        wxString msg;
        PreOrderTraverse(T, abc);
        msg.Printf(wxT("������������������ǣ�"),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("��������������"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 8) {
        wxString abc;
        wxString msg;
        InOrderTraverse(T, abc);
        msg.Printf(wxT("������������������ǣ�"),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("��������������"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 9) {
        wxString count;
        count << Leaf(T);
        wxString msg;
        msg.Printf(wxT("Ҷ�ӽ��ĸ���Ϊ"),
            wxVERSION_STRING);
        msg = msg + count;
        wxMessageBox(msg, wxT("ͳ��Ҷ�ӽ��"),
            wxOK | wxICON_INFORMATION, this);
    }
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(350, 260),
        wxCAPTION| wxMINIMIZE_BOX| wxCLOSE_BOX| wxSYSTEM_MENU)
{
    wxPanel* panel = new wxPanel(this, -1);

    wxStaticBox* kuang1 = new wxStaticBox(panel, wxID_ANY, wxT("����"));
    wxStaticBox * kuang2 = new wxStaticBox(panel, wxID_ANY, wxT("����"));
    wxStaticBoxSizer* staticSizer1 = new wxStaticBoxSizer(kuang1, wxVERTICAL);
    wxStaticBoxSizer* staticSizer2 = new wxStaticBoxSizer(kuang2, wxVERTICAL);

    wxFlexGridSizer* hbox = new wxFlexGridSizer(2, 1, 9, 25);
    wxFlexGridSizer* h1 = new wxFlexGridSizer(1, 3, 9, 25);
    wxFlexGridSizer* fgs = new wxFlexGridSizer(3, 3, 9, 25);

    wxStaticText* Create = new wxStaticText(panel, -1, wxT("�ڴ���������"));
    tc0 = new wxTextCtrl(panel, -1);

    wxButton* CreateBiTree = new wxButton(panel, wxID111, wxT("���ɶ�����"));
    wxButton* PreOrderTraverse = new wxButton(panel, 10, wxT("�������"));
    wxButton* InOrderTraverse = new wxButton(panel, 2, wxT("�������"));
    wxButton* PosOrderTraverse = new wxButton(panel, 3, wxT("�������"));
    wxButton* PreOrderThreading = new wxButton(panel, 4, wxT("����������"));
    wxButton* InOrderThreading = new wxButton(panel, 5, wxT("����������"));
    wxButton* PosOrderThreading = new wxButton(panel, 6, wxT("����������"));
    wxButton* PreTraverse = new wxButton(panel, 7, wxT("��������������"));
    wxButton* InTraverse = new wxButton(panel, 8, wxT("��������������"));
    wxButton* leafcount = new wxButton(panel, 9, wxT("Ҷ�ӽ�����"));
    
    CreateBiTree->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    PreOrderTraverse->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    InOrderTraverse->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    PosOrderTraverse->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    PreOrderThreading->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    InOrderThreading->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    PosOrderThreading->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    PreTraverse->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    InTraverse->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);
    leafcount->Bind(wxEVT_BUTTON, &MyFrame::OnButton_1, this);


    //�ֱ�˳����ӵ�������
    h1->Add(Create);
    h1->Add(tc0, 1, wxEXPAND);
    h1->Add(CreateBiTree);
    fgs->Add(PreOrderTraverse);
    fgs->Add(PreOrderThreading);
    fgs->Add(PreTraverse);
    fgs->Add(InOrderTraverse);
    fgs->Add(InOrderThreading);
    fgs->Add(InTraverse);
    fgs->Add(PosOrderTraverse);
    fgs->Add(PosOrderThreading);
    fgs->Add(leafcount);
    staticSizer1->Add(h1);
    staticSizer2->Add(fgs);
    hbox->Add(staticSizer1);
    hbox->Add(staticSizer2);
    panel->SetSizer(hbox);


    // �����˵���
    wxMenu* fileMenu = new wxMenu;
    // ��ӡ����ڡ��˵���
    wxMenu* helpMenu = new wxMenu;


    helpMenu->Append(wxID_ABOUT, wxT("����\tF1"),
        wxT("Show about dialog"));

    fileMenu->Append(wxID_EXIT, wxT("�˳�\tAlt-X"),
        wxT("Quit this program"));

    // ���˵�����ӵ��˵�����
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("�ļ�"));
    menuBar->Append(helpMenu, wxT("����"));


    // ...Ȼ�󽫲˵�����������������
    SetMenuBar(menuBar);

    // ����һ��״̬������һ�и���ȤЩ��
    CreateStatusBar(2);
    SetStatusText(wxT("��ӭʹ�ö�������"));

}