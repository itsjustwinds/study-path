const
        fi='mahoa2.inp';
        fo='mahoa2.out';
var
        s,dem1,s1:string;
        i,j,dem,x:longint;
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
        dem1:='';
        for i:=1 to length(s) do
        begin
                if not (s[i] in ['A'..'Z']) then
                        dem1:=dem1+s[i];
                if s[i] in ['A'..'Z'] then
                begin
                        val(dem1,dem,x);
                        for j:=1 to dem do
                                write(f,s[i]);
                        dem1:='';
                end;
        end;
        close(f);
end;
begin
        nhap;
        xuat;
end.
