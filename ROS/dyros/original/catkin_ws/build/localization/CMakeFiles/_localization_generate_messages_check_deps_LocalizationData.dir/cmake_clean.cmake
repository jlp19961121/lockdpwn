FILE(REMOVE_RECURSE
  "CMakeFiles/_localization_generate_messages_check_deps_LocalizationData"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/_localization_generate_messages_check_deps_LocalizationData.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)