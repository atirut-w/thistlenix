.segment "CODE"

.include "subroutines/print.s"
.include "subroutines/printhex.s"
.include "component.s"

.segment "RODATA"

.scope text
newline: .byte 10, 0
helloworld: .byte "Hello, World!", 10, 0
compcount: .byte "Component Count: ", 0
.endscope

.segment "STARTUP"
    lda #>text::compcount
    pha
    lda #<text::compcount
    pha
    jsr print

    jsr component::get_count
    jsr printhex

    lda #>text::newline
    pha
    lda #<text::newline
    pha
    jsr print

    jsr component::list_components

    rts
