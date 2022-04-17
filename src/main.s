.include "subroutines/print.s"

.segment "STARTUP"
    ldx #<text
    jsr print
    rts

text:
    .byte "Hello World!", $0a, 0
