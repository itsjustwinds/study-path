const
        fi='karaoke.inp';
        fo='karaoke.out';
var
        s:string;
        t,bd,kt,tg,i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        read(f,bd,kt);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f); t:=0;
        if (s='Hai') or (s='Ba') or (s='Tu') or(s='Nam') or(s='Sau') then
        begin
                if kt<=14 then
                begin
                        tg:=kt-bd;
                        if tg<=3 then
                                for i:=1 to tg do
                                        t:=t+50000
                        else t:=3*50000+(tg-3)*40000;
                end
                else
                begin
                        if bd>=14 then
                        begin
                                tg:=kt-bd;
                                t:=3*60000+(tg-3)*48000;
                        end
                        else
                        begin
                                tg:=kt-bd;
                                if tg<=3 then
                                        t:=(14-bd)*50000+(kt-14)*60000
                                else
                                begin
                                        if 14-bd<=3 then
                                        begin
                                                t:=t+(14-bd)*50000;
                                                t:=t+(3-14+bd)*60000+(tg-3)*48000;
                                        end;
                                        if 14-bd>3 then
                                        begin
                                                t:=3*50000+(14-3-bd)*40000;
                                                t:=t+(kt-14)*48000;
                                        end;
                                end;
                        end;
                end;
        end;
        if (s='Bay') or(s='Chu nhat') then
                t:=(kt-bd)*70000;
        write(f,t);
        close(f);
end;
begin
        nhap;
        xuly;
end.
