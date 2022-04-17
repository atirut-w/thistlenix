.segment "CODE"

; Subroutines
.include "subroutines/print.s"

.segment "RODATA"

text:
    .byte "Hello World!", $0a, 0

.segment "STARTUP"
    ldx #<text
    jsr print
    rts
