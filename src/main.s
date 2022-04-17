.segment "CODE"

.include "subroutines/print.s"
.include "subroutines/printhex.s"

.segment "RODATA"

.scope text
newline: .byte 10, 0
helloworld: .byte "Hello, World!", 10, 0
.endscope

.segment "STARTUP"
    lda #>text::helloworld
    pha
    lda #<text::helloworld
    pha
    jsr print

    lda #$13
    pha
    jsr printhex

    lda #>text::newline
    pha
    lda #<text::newline
    pha
    jsr print

    rts
