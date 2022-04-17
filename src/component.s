.ifndef _COMPONENT_S_
_COMPONENT_S_ = 1

; Component-related subroutines. Mostly wrappers around the component mapper.
; See: https://github.com/gamax92/Thistle/wiki/Component-Mapper

.include "errno.s"
.include "subroutines/print.s"
.include "subroutines/printhex.s"

.scope component

.proc get_count
    pla
    sta return_addr
    pla
    sta return_addr+1

    lda #3
    sta $e010

    lda $e010
    cmp #0
    bne error

    lda $e011
    pha
    jmp end

error:
    lda #EIO
    sta errno
    lda #0
    pha

end:
    lda return_addr+1
    pha
    lda return_addr
    pha
    rts

return_addr: .res 2
.endproc

.proc list_components
    jsr get_count
    pla
    sta component_count
    ldx #0

loop:
    lda i
    pha
    jsr printhex

    lda #>newline
    pha
    lda #<newline
    pha
    jsr print

    lda i
    cmp component_count
    beq end
    inc
    sta i
    jmp loop

end:
    rts

newline: .byte 10, 0
component_count: .byte 0
i: .byte 0
.endproc

.endscope

.endif
