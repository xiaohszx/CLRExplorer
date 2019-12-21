#pragma once

class DataTarget;

class CCLRDataTarget : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public ICLRDataTarget {
public:
	BEGIN_COM_MAP(CCLRDataTarget)
		COM_INTERFACE_ENTRY(ICLRDataTarget)
	END_COM_MAP()

	HRESULT Init(DataTarget* dt);
	void FinalRelease();

	// ICLRDataTarget
	HRESULT __stdcall GetMachineType(ULONG32* machineType) override;
	HRESULT __stdcall GetPointerSize(ULONG32* pointerSize) override;
	HRESULT __stdcall GetImageBase(LPCWSTR imagePath, CLRDATA_ADDRESS* baseAddress) override;
	HRESULT __stdcall ReadVirtual(CLRDATA_ADDRESS address, BYTE* buffer, ULONG32 bytesRequested, ULONG32* bytesRead) override;
	HRESULT __stdcall WriteVirtual(CLRDATA_ADDRESS address, BYTE* buffer, ULONG32 bytesRequested, ULONG32* bytesWritten) override;
	HRESULT __stdcall GetTLSValue(ULONG32 threadID, ULONG32 index, CLRDATA_ADDRESS* value) override;
	HRESULT __stdcall SetTLSValue(ULONG32 threadID, ULONG32 index, CLRDATA_ADDRESS value) override;
	HRESULT __stdcall GetCurrentThreadID(ULONG32* threadID) override;
	HRESULT __stdcall GetThreadContext(ULONG32 threadID, ULONG32 contextFlags, ULONG32 contextSize, BYTE* context) override;
	HRESULT __stdcall SetThreadContext(ULONG32 threadID, ULONG32 contextSize, BYTE* context) override;
	HRESULT __stdcall Request(ULONG32 reqCode, ULONG32 inBufferSize, BYTE* inBuffer, ULONG32 outBufferSize, BYTE* outBuffer) override;

private:
	DataTarget* m_Target;
	HANDLE m_hProcess{ nullptr };
};

