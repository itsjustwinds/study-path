const
        fi='demxau.inp';
        fo='demxau.out';
var
        s:string;
        a:array[1..100000] of longint;
        i,dem:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,s);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        a[1]:=1;
        dem:=1;
        for i:=2 to length(s) do
        begin
                if (s[i]='0') or (s[i-1]='0') then
                        a[i]:=a[i-1]+1
                        else a[i]:=1;
                dem:=dem+a[i];
        end;
        write(f,dem);
        close(f);
end;
begin
        nhap;
        xuly;
        end.