#pragma once

#include "DownloadComponent.h"

class DownloadGroupConfiguration
{
public:
	// download window caption
	std::wstring caption;
	// help message
	std::wstring help_message;
	// progress message
	std::wstring downloading_message;
	// start button caption
	std::wstring start_caption;
	// cancel button caption
	std::wstring cancel_caption;
	// download components
	std::vector< DownloadComponentInfoPtr > downloadcomponents;
	// auto-start download
	bool auto_start;
public:
	DownloadGroupConfiguration();
	~DownloadGroupConfiguration();
	void Load(TiXmlElement * node);
};

typedef shared_any<DownloadGroupConfiguration *, close_delete> DownloadGroupConfigurationPtr;