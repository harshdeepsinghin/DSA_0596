---
created-date: 2024-04-09 17:35
---

### Parsing the flags

```C
while (argc > 1)
    {
        while (argv[1][0] == '-')
        {
            switch (argv[1][1])
            {
                case 'a':
                    printf("a is %s\n", argv[2]);
                    break;
                case 'b':
                    printf("b is %s\n", argv[2]);
                    break;
                default:
                    printf("default\n");
                    break;
            }
            argv++;
            argc--;
        }
        argv++;
        argc--;
    }
```