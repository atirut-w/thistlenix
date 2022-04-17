.segment "CODE"

; Subroutines
.include "subroutines/print.s"
.include "subroutines/printhex.s"

; Libraries
.include "errno.s"
.include "component.s"

.segment "RODATA"

.scope text
newline: .byte $0a, 0
component_count: .byte "Component count: ", 0
.endscope

.segment "STARTUP"
    ldx #<text::component_count
    jsr print

    jsr component::get_count
    jsr printhex

    ldx #<text::newline
    jsr print

    rts
