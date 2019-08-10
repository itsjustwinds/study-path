const
        fi='thugon.inp';
        fo='thugon.out';
var
        s:string;
        i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,s);
        close(f);
end;
procedure xoa;
begin
        while pos(' ',s)<>0 do
                delete(s,pos(' ',s),1);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        repeat
                if length(s)>1 then
                begin
                        for i:=1 to length(s) do
                                if i mod 2=0 then
                                begin
                                        delete(s,i,1);
                                        insert(' ',s,i);
                                end;
                end;
                xoa;
                if length(s)>1 then
                begin
                        for i:=1 to length(s) do
                                if i mod 2<>0 then
                                begin
                                        delete(s,i,1);
                                        insert(' ',s,i);
                                end;
                end;
                xoa;
        until length(s)=1;
        write(f,s);
        close(f);
end;
begin
        nhap;
        xuat;
end.