#pragma once

#include "IListView.h"

enum class NodeType : size_t {
	Root,
	Summary,
	AppDomains,
	AllAssemblies,
	AllModules,
	ThreadPool,
	Threads,
	GCHeaps,
	SyncBlocks,
	AllStrings,
	HeapStats,
	MethodTable = 0x100,
	None = (size_t)-1
};

struct IGenericListView {
	virtual IListView* GetListView() = 0;
	virtual void Refresh() = 0;
	virtual void SetListViewItemCount(int count) = 0;
};

struct IDialogBarProvider {
	virtual HWND Create(HWND hParent) = 0;
	virtual bool HandleCommand(UINT cmd) {
		return false;
	}
};

struct IGenericListViewCallback {
	virtual int GetItemCount() = 0;
	virtual bool Init(CListViewCtrl& lv, IGenericListView* glv) = 0;
	virtual CString GetItemText(int row, int col) = 0;
	virtual int GetIcon(int row) {
		return -1;
	}
	virtual bool Sort(int column, bool ascending) = 0;
	virtual bool CanSort(int column) const {
		return true;
	}
	virtual void OnContextMenu(const POINT& pt, int selected) {}
	virtual void ExecuteCommand(WORD id) {}
	virtual bool CanExecuteCommand(WORD id) {
		return true;
	}
	virtual void OnDoubleClick(int selected) {}
};

struct IToolBarProvider {
	virtual bool Init(CToolBarCtrl& tb) = 0;
	virtual bool OnCommand(WORD id) = 0;
};

struct IMainFrame {
	virtual int FindTab(DWORD_PTR data) = 0;
	virtual void SwitchToPage(int page) = 0;
	virtual void AddTab(DWORD_PTR type, NodeType genericType = NodeType::None, NodeType parent = NodeType::None) = 0;
	virtual UINT ShowContextMenu(HMENU hMenu, const POINT& pt, DWORD flags = 0) = 0;
};
