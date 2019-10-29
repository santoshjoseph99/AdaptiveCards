// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "pch.h"
#include "LinkButton.h"
#include <windows.ui.xaml.automation.peers.h>

using namespace Microsoft::WRL;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Automation;
using namespace ABI::Windows::UI::Xaml::Automation::Peers;

namespace AdaptiveNamespace
{
    HRESULT LinkButtonAutomationPeer::RuntimeClassInitialize()
    {
        ComPtr<IAutomationPeerFactory> spInnerFactory;
        ComPtr<IInspectable> spInnerInspectable;
        ComPtr<IAutomationPeer> spInnerAutomationPeer;

        RETURN_IF_FAILED(GetActivationFactory(HStringReference(RuntimeClass_Windows_UI_Xaml_Automation_Peers_AutomationPeer).Get(),
                                              &spInnerFactory));
        RETURN_IF_FAILED(spInnerFactory->CreateInstance(static_cast<IAutomationPeerOverrides*>(this), &spInnerInspectable, &spInnerAutomationPeer));
        RETURN_IF_FAILED(SetComposableBasePointers(spInnerInspectable.Get(), spInnerFactory.Get()));

        return S_OK;
    }

    // IAutomationPeerOverrides methods
    IFACEMETHODIMP LinkButtonAutomationPeer::GetPatternCore(_In_ PatternInterface patternInterface, _Outptr_ IInspectable** ppReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetPatternCore(patternInterface, ppReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetAcceleratorKeyCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetAcceleratorKeyCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetAccessKeyCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetAccessKeyCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetAutomationControlTypeCore(_Out_ AutomationControlType* pReturnValue)
    {
        *pReturnValue = AutomationControlType::AutomationControlType_Hyperlink;
        return S_OK;
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetAutomationIdCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetAutomationIdCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetBoundingRectangleCore(_Out_ Rect* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetBoundingRectangleCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetChildrenCore(_Outptr_ IVector<AutomationPeer*>** ppReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetChildrenCore(ppReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetClassNameCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetClassNameCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetClickablePointCore(_Out_ Point* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetClickablePointCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetHelpTextCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetHelpTextCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetItemStatusCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetItemStatusCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetItemTypeCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetItemTypeCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetLabeledByCore(_Outptr_ IAutomationPeer** ppReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetLabeledByCore(ppReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetLocalizedControlTypeCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetLocalizedControlTypeCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetNameCore(_Out_ HSTRING* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetNameCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetOrientationCore(_Out_ AutomationOrientation* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetOrientationCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::HasKeyboardFocusCore(_Out_ BOOLEAN* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->HasKeyboardFocusCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::IsContentElementCore(_Out_ BOOLEAN* pReturnValue)
    {
        *pReturnValue = TRUE;
        return S_OK;
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::IsControlElementCore(_Out_ BOOLEAN* pReturnValue)
    {
        *pReturnValue = TRUE;
        return S_OK;
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::IsEnabledCore(_Out_ BOOLEAN* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->IsEnabledCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::IsKeyboardFocusableCore(_Out_ BOOLEAN* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->IsKeyboardFocusableCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::IsOffscreenCore(_Out_ BOOLEAN* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->IsOffscreenCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::IsPasswordCore(_Out_ BOOLEAN* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->IsPasswordCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::IsRequiredForFormCore(_Out_ BOOLEAN* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->IsRequiredForFormCore(pReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::SetFocusCore()
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->SetFocusCore();
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetPeerFromPointCore(_In_ Point point, _Outptr_ IAutomationPeer** ppReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetPeerFromPointCore(point, ppReturnValue);
    }

    IFACEMETHODIMP LinkButtonAutomationPeer::GetLiveSettingCore(_Out_ AutomationLiveSetting* pReturnValue)
    {
        ComPtr<IAutomationPeerOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->GetLiveSettingCore(pReturnValue);
    }

    HRESULT LinkButton::RuntimeClassInitialize()
    {
        ComPtr<IFrameworkElementFactory> spInnerFactory;
        ComPtr<IInspectable> spInnerInspectable;
        ComPtr<IFrameworkElement> spInnerFrameworkElement;

        RETURN_IF_FAILED(GetActivationFactory(HStringReference(RuntimeClass_Windows_UI_Xaml_FrameworkElement).Get(), &spInnerFactory));
        RETURN_IF_FAILED(spInnerFactory->CreateInstance(this, &spInnerInspectable, &spInnerFrameworkElement));
        RETURN_IF_FAILED(SetComposableBasePointers(spInnerInspectable.Get(), spInnerFactory.Get()));

        return S_OK;
    }

    // IUIElementOverrides
    IFACEMETHODIMP LinkButton::OnCreateAutomationPeer(__deref_out_opt IAutomationPeer** ppReturnValue)
    {
        if (!m_ap)
        {
            RETURN_IF_FAILED(MakeAndInitialize<LinkButtonAutomationPeer>(&m_ap));
        }
        return m_ap.CopyTo(ppReturnValue);
    }

    IFACEMETHODIMP LinkButton::OnDisconnectVisualChildren()
    {
        ComPtr<IUIElementOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->OnDisconnectVisualChildren();
    }

    IFACEMETHODIMP LinkButton::FindSubElementsForTouchTargeting(__in Point point,
                                                                __in Rect boundingRect,
                                                                __deref_out IIterable<IIterable<Point>*>** returnValue)
    {
        ComPtr<IUIElementOverrides> overrides;
        RETURN_IF_FAILED(GetComposableBase().As(&overrides));
        return overrides->FindSubElementsForTouchTargeting(point, boundingRect, returnValue);
    }
}
