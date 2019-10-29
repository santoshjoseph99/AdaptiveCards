// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include <wrl.h>
#include <windows.ui.h>
#include <windows.ui.xaml.h>

namespace AdaptiveNamespace
{
    class LinkButtonAutomationPeer
        : public Microsoft::WRL::RuntimeClass<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides,
                                              Microsoft::WRL::ComposableBase<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerFactory>>
    {
        InspectableClass(L"LinkButtonAutomationPeer", BaseTrust);

    public:
        HRESULT RuntimeClassInitialize();

        // IAutomationPeerOverrides
        IFACEMETHODIMP GetPatternCore(_In_ ABI::Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface,
                                      _Outptr_ IInspectable** ppReturnValue);
        IFACEMETHODIMP GetAcceleratorKeyCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetAccessKeyCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetAutomationControlTypeCore(_Out_ ABI::Windows::UI::Xaml::Automation::Peers::AutomationControlType* pReturnValue);
        IFACEMETHODIMP GetAutomationIdCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetBoundingRectangleCore(_Out_ ABI::Windows::Foundation::Rect* pReturnValue);
        IFACEMETHODIMP GetChildrenCore(_Outptr_ ABI::Windows::Foundation::Collections::IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>** ppReturnValue);
        IFACEMETHODIMP GetClassNameCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetClickablePointCore(_Out_ ABI::Windows::Foundation::Point* pReturnValue);
        IFACEMETHODIMP GetHelpTextCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetItemStatusCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetItemTypeCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetLabeledByCore(_Outptr_ ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer** ppReturnValue);
        IFACEMETHODIMP GetLocalizedControlTypeCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetNameCore(_Out_ HSTRING* pReturnValue);
        IFACEMETHODIMP GetOrientationCore(_Out_ ABI::Windows::UI::Xaml::Automation::Peers::AutomationOrientation* pReturnValue);
        IFACEMETHODIMP HasKeyboardFocusCore(_Out_ BOOLEAN* pReturnValue);
        IFACEMETHODIMP IsContentElementCore(_Out_ BOOLEAN* pReturnValue);
        IFACEMETHODIMP IsControlElementCore(_Out_ BOOLEAN* pReturnValue);
        IFACEMETHODIMP IsEnabledCore(_Out_ BOOLEAN* pReturnValue);
        IFACEMETHODIMP IsKeyboardFocusableCore(_Out_ BOOLEAN* pReturnValue);
        IFACEMETHODIMP IsOffscreenCore(_Out_ BOOLEAN* pReturnValue);
        IFACEMETHODIMP IsPasswordCore(_Out_ BOOLEAN* pReturnValue);
        IFACEMETHODIMP IsRequiredForFormCore(_Out_ BOOLEAN* pReturnValue);
        IFACEMETHODIMP SetFocusCore();
        IFACEMETHODIMP GetPeerFromPointCore(_In_ ABI::Windows::Foundation::Point point, _Outptr_ ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer** ppReturnValue);
        IFACEMETHODIMP GetLiveSettingCore(_Out_ ABI::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting* pReturnValue);
    };

    class LinkButton : public Microsoft::WRL::RuntimeClass<ABI::Windows::UI::Xaml::IUIElementOverrides, Microsoft::WRL::ComposableBase<ABI::Windows::UI::Xaml::IFrameworkElementFactory>>
    {
        InspectableClass(L"LinkButton", BaseTrust);

    public:
        HRESULT RuntimeClassInitialize();

        // IUIElementOverrides
        IFACEMETHODIMP OnCreateAutomationPeer(__deref_out_opt ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer** ppReturnValue);
        IFACEMETHODIMP OnDisconnectVisualChildren();
        IFACEMETHODIMP FindSubElementsForTouchTargeting(__in ABI::Windows::Foundation::Point point,
                                                        __in ABI::Windows::Foundation::Rect boundingRect,
            __deref_out ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Point>*>** returnValue);

    private:
        Microsoft::WRL::ComPtr<LinkButtonAutomationPeer> m_ap;
    };
}
