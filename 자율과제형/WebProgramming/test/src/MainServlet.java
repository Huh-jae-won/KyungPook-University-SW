

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/main")	// 사용자 요청 주소
public class MainServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
//     	user -> 바로 jsp파일로 요청 불가
//		user -> servlet에 요청(사용자요청주소 : /main) -> servlet이 상대적 주소(/WEB-INF/index.jsp) 반환
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		RequestDispatcher rd = request.getRequestDispatcher("/WEB-INF/index.jsp");	// 상대적 주소를 적어줌
		rd.forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	}
}
