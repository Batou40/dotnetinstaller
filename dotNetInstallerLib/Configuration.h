#pragma once

class Component;

#include "WidgetPosition.h"
#include "XmlAttribute.h"

enum configuration_type
{
	configuration_unknown = 0,
	configuration_install,
	configuration_reference
};

class Configuration
{
public:
	// configuration lcid filter
	XmlAttribute lcid_filter;
	// configuration language
	XmlAttribute language;
	XmlAttribute language_id;
	// filter for operating system version
	XmlAttribute os_filter;
	// filter for minimum operating system version
	XmlAttribute os_filter_greater;
	// filter for maximum operating system version
	XmlAttribute os_filter_smaller;
	// filter for processor architecture
	XmlAttribute processor_architecture_filter;
	// configuration type
	configuration_type type;
	// install mode
	bool supports_install;
	bool supports_uninstall;
public:
	Configuration(configuration_type t);
	virtual void Load(TiXmlElement * node);
	// returns true if this configuration is supported on this operating system/lcid
	virtual bool IsSupported(LCID lcid) const;
	virtual std::wstring GetLanguageString() const;
	virtual std::wstring GetString(int indent = 0) const;
};

typedef shared_any<Configuration *, close_delete> ConfigurationPtr;
