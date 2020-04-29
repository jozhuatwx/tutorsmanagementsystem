# Changelog

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
