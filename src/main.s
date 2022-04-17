.segment "CODE"

; Subroutines
.include "subroutines/print.s"
.include "subroutines/printhex.s"

.segment "RODATA"

text:
    .byte "Hello World!", $0a, 0

.segment "STARTUP"
    ldx #<text
    jsr print
    ldx #$13
    jsr printhex
    rts
