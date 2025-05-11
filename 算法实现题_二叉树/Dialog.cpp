#include "wx/wx.h"
#include "wx/button.h"
#include <wx/sizer.h>
#include <wx/gbsizer.h>
#include "BiTree.h"

// 定义应用程序类
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// 定义主窗口类
class MyFrame : public wxFrame
{
public:
    // 主窗口类的构造函数
    MyFrame(const wxString& title);
    
    // 事件处理函数
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton_1(wxCommandEvent& event);

    wxTextCtrl* tc0;

private:
    // 声明事件表
    DECLARE_EVENT_TABLE()
};

// 有了这一行就可以使用 MyApp& wxGetApp()了
DECLARE_APP(MyApp)

// 告诉wxWidgets主应用程序是哪个类
IMPLEMENT_APP(MyApp)

// 初始化程序
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(wxT("二叉树"));
    frame->Show(true);
    return true;
}

enum {
    wxID111,
};

// MyFrame类的事件表
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("输入所需生成的树的先序序列，内部结点用一个字符表示，空结点用#表示。"),
        wxVERSION_STRING);

    wxMessageBox(msg, wxT("如何创建树？"),
        wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
    // 释放主窗口
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
        msg.Printf(wxT("生成成功！"),
            wxVERSION_STRING);
        wxMessageBox(msg, wxT("生成二叉树"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 10) {
        wxString abc;
        wxString msg;
        PreOrderTraverse(T,abc);
        msg.Printf(wxT("先序遍历结果为："),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("先序遍历"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 2) {
        wxString abc;
        wxString msg;
        InOrderTraverse(T,abc);
        msg.Printf(wxT("中序遍历结果为："),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("中序遍历"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 3) {
        wxString abc;
        wxString msg;
        PosOrderTraverse(T,abc);
        msg.Printf(wxT("后序遍历结果为："),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("后序遍历"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 4) {
        wxString msg;
        PreOrderThreading(Thrt, T);
        msg.Printf(wxT("先序线索化完成！"),
            wxVERSION_STRING);
        wxMessageBox(msg, wxT("先序线索化"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 5) {
        wxString msg;
        InOrderThreading(Thrt,T);
        msg.Printf(wxT("中序线索化完成！"),
            wxVERSION_STRING);
        wxMessageBox(msg, wxT("中序线索化"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 6) {
        wxString msg;
        msg.Printf(wxT("后序线索化完成！"),
            wxVERSION_STRING);
        wxMessageBox(msg, wxT("后序线索化"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 7) {
        wxString abc;
        wxString msg;
        PreOrderTraverse(T, abc);
        msg.Printf(wxT("先序线索化遍历结果是："),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("先序线索化遍历"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 8) {
        wxString abc;
        wxString msg;
        InOrderTraverse(T, abc);
        msg.Printf(wxT("中序线索化遍历结果是："),
            wxVERSION_STRING);
        msg = msg + abc;
        wxMessageBox(msg, wxT("中序线索化遍历"),
            wxOK | wxICON_INFORMATION, this);
    }
    else if (iddd == 9) {
        wxString count;
        count << Leaf(T);
        wxString msg;
        msg.Printf(wxT("叶子结点的个数为"),
            wxVERSION_STRING);
        msg = msg + count;
        wxMessageBox(msg, wxT("统计叶子结点"),
            wxOK | wxICON_INFORMATION, this);
    }
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(350, 260),
        wxCAPTION| wxMINIMIZE_BOX| wxCLOSE_BOX| wxSYSTEM_MENU)
{
    wxPanel* panel = new wxPanel(this, -1);

    wxStaticBox* kuang1 = new wxStaticBox(panel, wxID_ANY, wxT("生成"));
    wxStaticBox * kuang2 = new wxStaticBox(panel, wxID_ANY, wxT("功能"));
    wxStaticBoxSizer* staticSizer1 = new wxStaticBoxSizer(kuang1, wxVERTICAL);
    wxStaticBoxSizer* staticSizer2 = new wxStaticBoxSizer(kuang2, wxVERTICAL);

    wxFlexGridSizer* hbox = new wxFlexGridSizer(2, 1, 9, 25);
    wxFlexGridSizer* h1 = new wxFlexGridSizer(1, 3, 9, 25);
    wxFlexGridSizer* fgs = new wxFlexGridSizer(3, 3, 9, 25);

    wxStaticText* Create = new wxStaticText(panel, -1, wxT("在此输入序列"));
    tc0 = new wxTextCtrl(panel, -1);

    wxButton* CreateBiTree = new wxButton(panel, wxID111, wxT("生成二叉树"));
    wxButton* PreOrderTraverse = new wxButton(panel, 10, wxT("先序遍历"));
    wxButton* InOrderTraverse = new wxButton(panel, 2, wxT("中序遍历"));
    wxButton* PosOrderTraverse = new wxButton(panel, 3, wxT("后序遍历"));
    wxButton* PreOrderThreading = new wxButton(panel, 4, wxT("先序线索化"));
    wxButton* InOrderThreading = new wxButton(panel, 5, wxT("中序线索化"));
    wxButton* PosOrderThreading = new wxButton(panel, 6, wxT("后序线索化"));
    wxButton* PreTraverse = new wxButton(panel, 7, wxT("先序线索树遍历"));
    wxButton* InTraverse = new wxButton(panel, 8, wxT("中序线索树遍历"));
    wxButton* leafcount = new wxButton(panel, 9, wxT("叶子结点个数"));
    
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


    //分别按顺序添加到布局里
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


    // 创建菜单条
    wxMenu* fileMenu = new wxMenu;
    // 添加“关于”菜单项
    wxMenu* helpMenu = new wxMenu;


    helpMenu->Append(wxID_ABOUT, wxT("关于\tF1"),
        wxT("Show about dialog"));

    fileMenu->Append(wxID_EXIT, wxT("退出\tAlt-X"),
        wxT("Quit this program"));

    // 将菜单项添加到菜单条中
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("文件"));
    menuBar->Append(helpMenu, wxT("帮助"));


    // ...然后将菜单条放置在主窗口上
    SetMenuBar(menuBar);

    // 创建一个状态条来让一切更有趣些。
    CreateStatusBar(2);
    SetStatusText(wxT("欢迎使用二叉树！"));

}