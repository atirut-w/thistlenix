.ifndef _COMPONENT_S_
_COMPONENT_S_ = 1

; Component-related subroutines. Mostly wrappers around the component mapper.
; See: https://github.com/gamax92/Thistle/wiki/Component-Mapper

.include "errno.s"

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

.endscope

.endif
