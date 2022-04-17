.ifndef _ERRNO_S_
_ERRNO_S_ = 1

.segment "DATA"

; Global `errno` variable.
errno: .res 1

EIO = 5

.endif
