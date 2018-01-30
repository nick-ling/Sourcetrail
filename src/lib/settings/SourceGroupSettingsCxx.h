#ifndef SOURCE_GROUP_SETTINGS_CXX_H
#define SOURCE_GROUP_SETTINGS_CXX_H

#include "settings/SourceGroupSettings.h"

class SourceGroupSettingsCxx
	: public SourceGroupSettings
{
public:
	SourceGroupSettingsCxx(const std::string& id, SourceGroupType type, const ProjectSettings* projectSettings);
	virtual ~SourceGroupSettingsCxx();

	virtual void load(std::shared_ptr<const ConfigManager> config) override;
	virtual void save(std::shared_ptr<ConfigManager> config) override;

	virtual bool equals(std::shared_ptr<SourceGroupSettings> other) const override;

	virtual std::vector<std::string> getAvailableLanguageStandards() const override;

	std::vector<FilePath> getHeaderSearchPaths() const;
	std::vector<FilePath> getHeaderSearchPathsExpandedAndAbsolute() const;
	void setHeaderSearchPaths(const std::vector<FilePath>& headerSearchPaths);

	std::vector<FilePath> getFrameworkSearchPaths() const;
	std::vector<FilePath> getFrameworkSearchPathsExpandedAndAbsolute() const;
	void setFrameworkSearchPaths(const std::vector<FilePath>& frameworkSearchPaths);

	std::vector<std::string> getCompilerFlags() const;
	void setCompilerFlags(const std::vector<std::string>& compilerFlags);

private:
	virtual std::vector<std::wstring> getDefaultSourceExtensions() const override;
	virtual std::string getDefaultStandard() const override;

	std::vector<FilePath> m_headerSearchPaths;
	std::vector<FilePath> m_frameworkSearchPaths;
	std::vector<std::string> m_compilerFlags;
};

#endif // SOURCE_GROUP_SETTINGS_CXX_H
