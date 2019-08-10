type bignum=string;
var
        t,n,i,j,k,max,h,d:longint;
        kq,dem:int64;
        x,y,z:string;
        sum,dd:array[1..2000000] of longint;
        a:array[1..10] of longint;
procedure sang_nt;
var     i,d:longint;
begin
        for i:=2 to 2*max do
                        if sum[i]=0 then
                        begin
                                sum[i]:=i;
                                d:=2;
                                while d*i<=2*max do
                                begin
                                        sum[d*i]:=i;
                                        inc(d);
                                end;
                        end;
end;
function cong(a,b : bigNum): bigNum;
var sum, carry, i, x, y : integer;
        c : bigNum;
begin
        carry:=0;c:='';
        while length(a)<length(b) do a:='0'+a;
        while length(b)<length(a) do b:='0'+b;
        for i:=length(a) downto 1 do
        begin
                x:= ord(a[i])-ord('0'); {ord('0')=48}
                y:= ord(b[i])-ord('0');
                sum:=x + y + carry;
                carry:=sum div 10;
                c:=chr(sum mod 10 +48)+c;
        end;
        if carry>0 then c:='1'+c;
        cong:=c;
end;
function nhan1(a:bigNum;b:longint):bigNum;
var     i :integer;
        carry,s :longint;
        c,tmp :bigNum;
begin
        c:='';
        carry:=0;
        for i:=length(a) downto 1 do
        begin
                s:=(ord(a[i])-48) * b + carry;
                carry:= s div 10;
                c:=chr(s mod 10 + 48)+c;
        end;
        if carry>0 then str(carry,tmp) else tmp:='';
        nhan1:=tmp+c;
end;
function nhan2(a,b:bigNum):bigNum;
var sum,tmp :bigNum;
        m,i,j :integer;
begin
        m:=-1;sum:='';
        for i:=length(a) downto 1 do
        begin
                m:=m+1;
                tmp:=nhan1(b,ord(a[i])-48);
                for j:=1 to m do tmp:=tmp+'0';
                        sum:=cong(tmp,sum);
        end;
        nhan2:=sum;
end;
procedure nhap;
begin
        readln(t);
        max:=0;
        for h:=1 to t do
        begin
                readln(a[h]);
                if a[h]>max then max:=a[h];
        end;
                fillchar(sum,sizeof(sum),false);
                sang_nt;
                for h:=1 to t do
                begin
                str(a[h],x);
                str(a[h]-1,y);
                str(a[h]-2,z);
                x:=nhan2(nhan2(x,y),z);
                val(x,kq,max);
                kq:=kq div 6;
                dem:=0;
                for i:=1 to a[h]-2 do
                        for j:=i+1 to a[h]-1 do
                                if (sum[i+j]=i+j) then
                                        inc(dem,a[h]-2);
                kq:=kq-dem;
                writeln(kq);
                end;
end;
begin
        assign(input,'coltri.inp');
        assign(output,'coltri.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
