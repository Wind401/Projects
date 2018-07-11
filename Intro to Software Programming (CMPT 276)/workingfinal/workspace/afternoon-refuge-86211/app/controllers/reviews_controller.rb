class ReviewsController < ApplicationController
  before_action :set_review, only: [:show, :edit, :update, :destroy]
  before_action :set_receiver
  before_action :authenticate_user!
  
  def index
    redirect_to @receiver
  end

  def show
    redirect_to @receiver
  end

  # GET /reviews/new
  def new
    if @receiver.id == current_user.id
      redirect_to @receiver
      flash[:notice] = "You cannot write a review for yourself." #DID NOT DISPLAY
    elsif Review.where(reviewer_id: current_user.id, receiver_id: @receiver.id).any?
      @reviewed = Review.where(reviewer_id: current_user.id, receiver_id: @receiver.id)
      redirect_to edit_user_review_path(@receiver.id, @reviewed.ids)
    else
      @review = Review.new
    end
  end

  # GET /reviews/1/edit
  def edit

  end

  # POST /reviews
  # POST /reviews.json
  def create
    @review = Review.new(review_params)
    @review.reviewer_id = current_user.id
    @review.receiver_id = @receiver.id

    if @review.save
      redirect_to @receiver
    else
      render 'new'
    end
  end

  # PATCH/PUT /reviews/1
  # PATCH/PUT /reviews/1.json
  def update
    if @review.update(review_params)
      redirect_to @receiver
    else
      render 'edit'
    end
  end

  # DELETE /reviews/1
  # DELETE /reviews/1.json
  def destroy
    @review.destroy
    respond_to do |format|
      format.html { redirect_to reviews_url, notice: 'Review was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_review
      @review = Review.find(params[:id])
    end
    
    def set_receiver
      @receiver = User.find(params[:user_id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def review_params
      params.require(:review).permit(:rating, :comment)
    end
end
