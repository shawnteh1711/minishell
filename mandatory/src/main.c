/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:14:12 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 12:35:33 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Main flow
// 1. lexer (lexical analyser, aka tokeniser), which converts an input string into tokens
// 2. parser which converts the tokens into appropriate data structures
// 3. executor which correctly executes and return the correct exit code
int main(int argc, char const *argv[])
{
	char *token;
	char *program;

	// seperate the command and save to each token
	token = lexical(argv);

	// parse each token into respective program
	program = parse(token);

	// execute each program
	execute(program);

	return 0;
}
