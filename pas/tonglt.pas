const
        fi='tonglt.inp';
        fo='tonglt.out';
var
        n,i,d,t,j:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
end;
procedure xuat;
var i,j: longint;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
     {   if (n=0) or (n=1) or (n=2) then
        begin
                write(f,d);
                close(f);
                exit;
        end;  }
        for i:=1 to (n div 2) do
        begin
                t:=0;
                for j:=i to (n div 2)+1 do
                begin
                        t:=t+j;
                        if t=n then
                        begin
                                inc(d);
                                break;
                        end;
                end;
        end;
        write(f,d);
        close(f);
end;
begin
        nhap;
        xuat;
end.

