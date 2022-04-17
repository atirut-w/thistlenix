.segment "CODE"

.include "subroutines/print.s"
.include "subroutines/printhex.s"
.include "component.s"

.segment "RODATA"

.scope text
newline: .byte 10, 0
helloworld: .byte "Hello, World!", 10, 0
.endscope

.segment "STARTUP"
    jsr component::get_count
    jsr printhex

    lda #>text::newline
    pha
    lda #<text::newline
    pha
    jsr print

    rts
