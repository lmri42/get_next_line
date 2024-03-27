## Variables

**remain** = `static char *remain` (malloc)

**line** = `char *line`

**buffer** = `char *buffer`

**bag** = `char *bag`

## Functions

**/* FT_STRLEN:**

- * Calculate the length of a string.
- *
- * Parameters:
- * - s: A pointer to the null-terminated string.
- *
- * Returns:
- * The length of the string.
- /

size_t	ft_strlen(const char *s);

**/* FT_SUBSTR:**

- * Create a substring from a string.
- *
- * Parameters:
- * - s: A pointer to the null-terminated string from which to create the
- * substring.
- * - start: The starting index of the substring in the string 's'.
- * - len: The maximum length of the substring.
- *
- * External functs:
- * malloc
- *
- * Returns:
- * A pointer to the newly allocated memory block containing the substring,
- * or NULL if allocation fails.
- /

char	*ft_substr(char const *s, unsigned int start, size_t len);

**/* FT_STRJOIN:**

- * Concatenate two strings into a newly allocated memory block.
- *
- * Parameters:
- * - s1: A pointer to the null-terminated prefix string.
- * - s2: A pointer to the null-terminated suffix string.
- *
- * External functs:
- * malloc
- *
- * Returns:
- * A pointer to the newly allocated memory block containing the concatenated
- *string, or NULL if allocation fails.
- /

char	*ft_strjoin(char const *s1, char const *s2);

**/* FT_STRDUP:**

- * Duplicate a string into a newly allocated memory block.
- *
- * Parameters:
- * - s1: A pointer to the null-terminated string to be duplicated.
- *
- * Returns:
- * A pointer to the newly allocated memory block containing the duplicated
- * string, or NULL if allocation fails.
- /

char	*ft_strdup(const char *s1);

**/* FT_STRDUP:**

- * Duplicate a string into a newly allocated memory block.
- *
- * Parameters:
- * - s1: A pointer to the null-terminated string to be duplicated.
- *
- * Returns:
- * A pointer to the newly allocated memory block containing the duplicated
- * string, or NULL if allocation fails.
- /

char	*ft_strdup(const char *s1);

## Recipe

- Check If there are more than 0 characters inside a static variable **remain** with a function to count characters. (ft_strlen)
    - If there are more than 0 characters :
        - Check for character “\n” inside **remain.**
            - If “\n” is found:
                - Copy characters from variable **remain**, from the first character until the first “\n”, to local variable **line.**
                - Copy characters from current variable **remain**, from the next character after the first “\n” until the last character of the string, to a new**<free+malloc>** static variable **remain.** <only if there are more characters, otherwise <**free>**>
                - RETURN (line);
            - If “\n” is NOT found:
                - Read() from a file descriptor(fd) for a BUFF_SIZE number of characters into a BUFF_SIZE + 1 size **buffer**. {If return from read is less than BUFF_SIZE, we arrived to the end!}
                - Add a “\0” character to the end [BUFF_SIZE + 1] of **buffer**.
                - Check for character “\n” inside **buffer.**
                    - If “\n” is found:
                        - Add characters from variable **remain** plus **buffer**, from the first character until the first “\n”, to variable **line.**  <variable **line** = remain + content + 1(**\0**)>
                        - Copy characters from variable **buffer**, from the next character after the first “\n” until the last character, to a new static variable **remain <free+malloc>.**  <only if there are more characters, otherwise <**free>**>
                        - RETURN (line);
                    - If “\n” is not found:
                        - **R —>** Add BUFF_SIZE characters from **buffer** to **bag**.
                        - Read() from a file descriptor(fd) for a BUFF_SIZE number of characters into a BUFF_SIZE + 1 size **buffer**. {If return from read is less than BUFF_SIZE, we arrived to the end.}
                            - Add a “\0” character to the end [BUFF_SIZE + 1] of **buffer**.
                            - Check for character “\n” inside **buffer.**
                                - If “\n” is found:
                                    - Add characters from variable **remain** plus **bag** plus **buffer**, from the first character until the first “\n”, to variable **line.**  <variable **line** = remain + bag + content + 1(**\0)**>
                                    - Copy characters from variable **buffer**, from the next character after the first “\n” until the last character, to a new static variable **remain. <free+malloc>** <only if there are more characters, otherwise <**free>**>
                                    - RETURN (line);
                                - If “\n” is not found: **(RECURSIVE)**
    - If there are no characters :
        - Read() from a file descriptor(fd) for a BUFF_SIZE number of characters into a BUFF_SIZE + 1 size **buffer**. {If return from read is less than BUFF_SIZE, we arrived to the end.}
        - Add a “\0” character to the end [BUFF_SIZE + 1] of **buffer**.
        - Check for character “\n” inside **buffer.**
            - If “\n” is found:
                - Add characters from variable **buffer**, from the first character until the first “\n”, to variable **line.**  <variable **line** =  content + 1(**\0**)>
                - Copy characters from variable **buffer**, from the next character after the first “\n” until the last character, to a new static variable **remain. <malloc>**
                - RETURN (line);
            - If “\n” is not found:
                - **R —>** Add BUFF_SIZE characters from **buffer** to **bag**.
                - Read() from a file descriptor(fd) for a BUFF_SIZE number of characters into a BUFF_SIZE + 1 size **buffer**. {If return from read is less than BUFF_SIZE, we arrived to the end.}
                    - Add a “\0” character to the end [BUFF_SIZE + 1] of **buffer**.
                    - Check for character “\n” inside **buffer.**
                        - If “\n” is found:
                            - Add characters from variables **bag** plus **buffer**, from the first character until the first “\n”, to variable **line.**  <variable **line** =  bag + content + 1(**\0**)>
                            - Copy characters from variable **buffer**, from the next character after the first “\n” until the last character, to a new static variable **remain. <free+malloc>**  <only if there are more characters, otherwise <**free>**>
                            - RETURN (line);
                        - If “\n” is not found: **(RECURSIVE)**
