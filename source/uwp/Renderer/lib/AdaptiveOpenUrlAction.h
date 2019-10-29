// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "OpenUrlAction.h"
#include "AdaptiveActionElement.h"

namespace AdaptiveNamespace
{
    class DECLSPEC_UUID("96c1ded5-1ef8-4aa8-8ccf-0bea96295ac8") AdaptiveOpenUrlAction
        : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                              ABI::AdaptiveNamespace::IAdaptiveOpenUrlAction,
                                              ABI::AdaptiveNamespace::IAdaptiveActionElement,
                                              Microsoft::WRL::CloakedIid<ITypePeek>,
                                              Microsoft::WRL::CloakedIid<AdaptiveNamespace::AdaptiveActionElementBase>>
    {
        AdaptiveRuntime(AdaptiveOpenUrlAction);

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(const std::shared_ptr<AdaptiveSharedNamespace::OpenUrlAction>& sharedOpenUrlAction);

        // IAdaptiveOpenUrlAction
        IFACEMETHODIMP get_Url(_COM_Outptr_ ABI::Windows::Foundation::IUriRuntimeClass** url);
        IFACEMETHODIMP put_Url(_In_ ABI::Windows::Foundation::IUriRuntimeClass* url);

        // IAdaptiveActionElement
        IFACEMETHODIMP get_ActionType(_Out_ ABI::AdaptiveNamespace::ActionType* actionType);
        IFACEMETHODIMP get_ActionTypeString(_Outptr_ HSTRING* value)
        {
            return AdaptiveActionElementBase::get_ActionTypeString(value);
        }

        IFACEMETHODIMP get_Title(_Outptr_ HSTRING* title) { return AdaptiveActionElementBase::get_Title(title); }
        IFACEMETHODIMP put_Title(_In_ HSTRING title) { return AdaptiveActionElementBase::put_Title(title); }

        IFACEMETHODIMP get_Id(_Outptr_ HSTRING* id) { return AdaptiveActionElementBase::get_Id(id); }
        IFACEMETHODIMP put_Id(_In_ HSTRING id) { return AdaptiveActionElementBase::put_Id(id); }

        IFACEMETHODIMP get_FallbackType(_Out_ ABI::AdaptiveNamespace::FallbackType* fallback)
        {
            return AdaptiveActionElementBase::get_FallbackType(fallback);
        }

        IFACEMETHODIMP get_FallbackContent(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveActionElement** content)
        {
            return AdaptiveActionElementBase::get_FallbackContent(content);
        }

        IFACEMETHODIMP put_FallbackType(ABI::AdaptiveNamespace::FallbackType fallback)
        {
            return AdaptiveActionElementBase::put_FallbackType(fallback);
        }

        IFACEMETHODIMP put_FallbackContent(_In_ ABI::AdaptiveNamespace::IAdaptiveActionElement* content)
        {
            return AdaptiveActionElementBase::put_FallbackContent(content);
        }

        IFACEMETHODIMP get_IconUrl(_Outptr_ HSTRING* iconUrl)
        {
            return AdaptiveActionElementBase::get_IconUrl(iconUrl);
        }
        IFACEMETHODIMP put_IconUrl(_In_ HSTRING iconUrl) { return AdaptiveActionElementBase::put_IconUrl(iconUrl); }

        IFACEMETHODIMP get_Style(_Outptr_ HSTRING* style) { return AdaptiveActionElementBase::get_Style(style); }
        IFACEMETHODIMP put_Style(_In_ HSTRING style) { return AdaptiveActionElementBase::put_Style(style); }

        IFACEMETHODIMP get_AdditionalProperties(_COM_Outptr_ ABI::Windows::Data::Json::IJsonObject** result)
        {
            return AdaptiveActionElementBase::get_AdditionalProperties(result);
        }
        IFACEMETHODIMP put_AdditionalProperties(_In_ ABI::Windows::Data::Json::IJsonObject* value)
        {
            return AdaptiveActionElementBase::put_AdditionalProperties(value);
        }

        IFACEMETHODIMP ToJson(_COM_Outptr_ ABI::Windows::Data::Json::IJsonObject** result)
        {
            return AdaptiveActionElementBase::ToJson(result);
        }

        virtual HRESULT GetSharedModel(std::shared_ptr<AdaptiveSharedNamespace::BaseActionElement>& sharedModel) override;

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }

    private:
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> m_url;
    };

    ActivatableClass(AdaptiveOpenUrlAction);
}
