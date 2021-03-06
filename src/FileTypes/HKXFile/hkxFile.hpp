#ifndef __FILETYPES__HKXFILE__HKXFILE_HPP__
#define __FILETYPES__HKXFILE__HKXFILE_HPP__

#include <list>

#include "FileTypes/HKXFile/hkClassName.hpp"
#include "FileTypes/HKXFile/hkLink.hpp"
#include "FileTypes/HKXFile/hkPointer.hpp"
#include "FileTypes/HKXFile/hkxHeader.hpp"
#include "FileTypes/HKXFile/hkxSectionHeader.hpp"

#include "Utils/FileUtils.hpp"

class hkRootLevelContainer;

/// Packfiles are composed of several sections.
/// A section contains several areas
/// | data | local | global | finish | exports | imports |
/// data: the user usable data.
/// local: pointer patches within this section (src,dst).
/// global: pointer patches to locations within this packfile (src,(section,dst)).
/// finish: offset and typename of all objects for finish functions (src, typename).
/// exports: named objects (src,name).
/// imports: named pointer patches outside this packfile (src,name).

namespace HKX {
	class HKXFile {
	private:
		std::unique_ptr<unsigned char[]> file;
	public:
		hkxHeader * m_header;
		std::list<hkxSectionHeader*> m_sectionHeaders;

		std::uint32_t class_name_global_address = 0;

		std::list<hkClassName> hkClassNames;
		std::list<hkType> hkTypes;
		std::list<hkLink> type_links;
		std::list<hkLink> data_links;
		std::list<hkPointer> data_pointers;
		std::list<hkPointer> data_global_pointers;
		std::uint32_t offsetRootLevelContainer = -1;
		hkRootLevelContainer * rootLevelContainer;
	private:
		void LoadStructure(std::uint32_t & currentOffset, std::string_view type_name);
		void LoadElement(std::uint32_t & currentOffset, std::string_view main_type);

	public:
		HKXFile() {}
		bool Load(std::string& filename);
		void TestStuff();
		std::uint32_t GetDataPointerTarget(std::uint32_t off);
		std::uint32_t GetGlobalDataPointerTarget(std::uint32_t off);
	};
}

#endif