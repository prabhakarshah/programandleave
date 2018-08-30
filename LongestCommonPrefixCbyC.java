class LongestCommonPrefixCbyC{
public String commonPrefix(List<String> strings) {
        Integer minsize = Collections.min(strings.stream()
                .map(s -> s.length())
                .collect(Collectors.toList()));
        int i = 0;
        for (; i < minsize; i++) {
            char c = strings.get(0).charAt(i);
            for (int j = 1; j < strings.size(); j++) {
                if (c != strings.get(j).charAt(i))
                    break;
            }
        }
        return strings.get(0).substring(0, i);
    }
}
