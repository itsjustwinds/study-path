const
        fi='minmax.inp';
        fo='minmax.out';
var
        s1,s2,s:string;
        i,j,c,x,n,n1,n2:longint;
        kq:int64;
        t:char;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n1,n2);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        str(n1,s1);str(n2,s2);
        s:=s1+s2;
        c:=length(s);
        for i:=length(s1) downto 1 do
                for j:=i to c do
                        if s[j]>=s[j+1] then
                        begin
                                t:=s[j];s[j]:=s[j+1];s[j+1]:=t;
                        end
                        else
                        begin
                                c:=j-2;
                                break;
                        end;
        val(s,kq,x);
        writeln(f,kq);
        s:=s1+s2;
        c:=length(s);
        for i:=length(s1) downto 1 do
                for j:=i to c do
                        if s[j]<=s[j+1] then
                        begin
                                t:=s[j];s[j]:=s[j+1];s[j+1]:=t;
                        end
                        else
                        begin
                                c:=j-2;
                                break;
                        end;
        val(s,kq,x);
        writeln(f,kq);
        close(f);
end;
begin

        nhap;
        xuat;
end.
