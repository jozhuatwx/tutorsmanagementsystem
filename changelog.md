# Changelog

## [2.2.4] - 8/5/2020
### Changed
- Added more comments for better clarity

### Fixed
- Minor bugfixes and optimisations

## [2.2.3] - 7/5/2020
### Fixed
- Minor bugfixes and optimisations

## [2.2.2] - 5/5/2020
### Fixed
- [#39](../../issues/39) Prevent modification of tuitions and subjects to same names

## [2.2.1] - 5/5/2020
### Changed
- Prevent tuition and subjects from being deleted if it is in use

### Removed
- Removed menu from suggesting the range for tuition code and subject code

### Fixed
- [#38](../../issues/38) Prevent addition of tuitions and subjects with the same name
- **LS:** [#36](../../issues/36) Jump list skips the first page under certain conditions
- **LS:** [#37](../../issues/37) Deleting tuition centre or subject does not update the size

## [2.2.0] - 5/5/2020
### Added
- [#33](../../issues/33) Function to modify tuition centres and subjects
- [#34](../../issues/34) Function to delete tuition centres and subjects

### Changed
- Updated display menu to ask to select function

### Fixed
- Fixed modify tutor menu to ask to select function
- Fixed wrong setter function for tuition centre name and subject name
- **LS:** Fixed occasional crashes when tuition centre name or subject name is unavailable

## [2.1.0] - 4/5/2020
### Added
- [#31](../../issues/31) Function to add new tuition centres and subjects
- [#32](../../issues/32) Function to display list of tuition centres and subjects

### Changed
- Added more hardcoded data for tuition centres and subjects

### Fixed
- [#35](../../issues/35) Getting non-existent tuition centre names or subjects crashes the system

## [2.0.2] - 4/5/2020
### Changed
- [#29](../../issues/29) Display limit of tuition centres and subjects when adding tutor

### Fixed
- [#30](../../issues/30) Prevent addition of tutors when there is no tuition centre or subject

## [2.0.1] - 4/5/2020
### Changed
- **AS:** [#27](../../issues/27) Update to binary search tuition centres and subjects

### Fixed
- Fixed [#28](../../issues/28) Hardcoded data is missing

## [2.0.0] - 30/4/2020
### Added
- Validates tuition centre code and subject code

### Changed
- Updated to separate tuition centres and subjects from tutors

## [1.0.1] - 13/4/2020
### Changed
- [#15](../../issues/15) Displaying in list view now shows longer tutor and tuition names, exceeded length are truncated
- **AS:** [#8](../../issues/8) Sorting by tutor ID has increased performance

### Fixed
- **AS:** Fixed [#6](../../issues/6) Adding tutor with duplicated name fails to sort correctly
- **AS:** Fixed [#7](../../issues/7) Sorting rating and hourly pay rate does not sort by ID
- **AS:** Fixed [#8](../../issues/9) Searching tuition name does not sort by ID
- **LS:** Fixed [#5](../../issues/5) Searching tuition name crashes the system


## [1.0.0] - 12/4/2020
### Changed
- Updated to display version number
- Updated to prevent date joined to be after current date
- Updated date to local time
- **AS:** Updated name to Array of Structures

### Fixed
- Fixed [#1](../../issues/1) Detailed view crashes system when searched a non-existent record
- **LL:** Fixed [#2](../../issues/2) Searching non-existent tuition name displays unintended results
- **LL:** Fixed [#4](../../issues/4) Memory leak when searching tuition name
- **AS:** Fixed [#3](../../issues/3) Searching non-existent tuition name crashes the system
