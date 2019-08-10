const
        fi='mahoa.inp';
        fo='mahoa.out';
var
        s,dem1,s1:string;
        i,dem,x:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        dem:=1;s1:='';
        for i:=1 to length(s) do
        begin
                if s[i]=s[i+1] then inc(dem)
                else
                begin
                        str(dem,dem1);
                        s1:=s1+dem1;
                        s1:=s1+s[i];
                        dem:=1;
                end;
        end;
         write(f,s1);
         close(f);
end;
begin
        nhap;
        xuat;
end.

